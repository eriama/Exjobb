#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <OpenNI.h>
#include <NI.h>

extern "C" {
using namespace openni;

#define SAMPLE_READ_WAIT_TIMEOUT 2000 //2000ms
void Sleep(int millisecs);
void analyzeFrame(const VideoFrameRef& frame);
void captureNI(uint16_T *depth);
void initNI();
void terminateNI();

class PrintCallback : public VideoStream::NewFrameListener{
public:
        void onNewFrame(VideoStream& stream);
		void destroy();
private:
        VideoFrameRef m_frame;
};

class OpenNIDeviceListener : public  openni::OpenNI::DeviceConnectedListener,
									public  openni::OpenNI::DeviceDisconnectedListener,
									public  openni::OpenNI::DeviceStateChangedListener
{
public:
	virtual void onDeviceStateChanged(const DeviceInfo* pInfo, DeviceState state){
		printf("Device \"%s\" error state changed to %d\n", pInfo->getUri(), state);
	}

	virtual void onDeviceConnected(const DeviceInfo* pInfo){
		printf("Device \"%s\" connected\n", pInfo->getUri());
	}

	virtual void onDeviceDisconnected(const DeviceInfo* pInfo){
		printf("Device \"%s\" disconnected\n", pInfo->getUri());
	}
};

int newFrame, fetched = 0;
bool run = 0;

Device device;
VideoStream depthStream;
PrintCallback depthPrinter;
uint16_t pDepth[320*240];
OpenNIDeviceListener devicePrinter;
void Sleep(int millisecs){usleep(millisecs * 1000);}

void PrintCallback::onNewFrame(VideoStream& stream){
    stream.readFrame(&m_frame);
    if(fetched ==1){
        analyzeFrame(m_frame);
		fetched = 0;
    }
}
void PrintCallback::destroy(){
	m_frame.release();
}


void captureNI(uint16_T *depth){
    if(newFrame > 0){ 
        for(int i = 0; i < 320*240; i++){
        depth[i] = pDepth[i];
        }
     newFrame = 0;
     fetched = 1;
    }
}

void analyzeFrame(const VideoFrameRef& frame){ 
    printf("FPS: %d\n", frame.getVideoMode().getFps() );
	int width = frame.getWidth();
	int height = frame.getHeight();  
	uint16_t tmp[240][320]; 
	int i = 0;
	DepthPixel* data; //= (DepthPixel*)malloc(320*240*sizeof(DepthPixel));
	switch (frame.getVideoMode().getPixelFormat()){
	case PIXEL_FORMAT_DEPTH_1_MM:
	case PIXEL_FORMAT_DEPTH_100_UM:
		printf("depth stream\n");
        data = (DepthPixel*)frame.getData();
		
         for (int y = 0; y < height; ++y){
            for (int x = 0; x < width; ++x, ++data){
                tmp[y][x] = *data;
            }
        }
		printf("Loop 1\n");
		
         for (int xx = 0; xx < width; ++xx){
            for (int yy = 0; yy < height; ++yy){
                pDepth[i] = tmp[yy][xx];
                i = i+1;
            }
        }
		printf("Loop 2\n");

		//delete [] data;
	break;
	case PIXEL_FORMAT_RGB888:
		printf("If we use rgb stream\n");
		break;
	default:
		printf("Unknown format\n");
	}
    newFrame++;
	printf("analyzeFrame done\n");
}
void initNI(){
	Status rc = OpenNI::initialize();
	if (rc != STATUS_OK)
	{
		printf("Initialize failed\n%s\n", OpenNI::getExtendedError());
		return;
	}
	
	OpenNI::addDeviceConnectedListener(&devicePrinter);
	OpenNI::addDeviceDisconnectedListener(&devicePrinter);
	OpenNI::addDeviceStateChangedListener(&devicePrinter);

	openni::Array<openni::DeviceInfo> deviceList;
	openni::OpenNI::enumerateDevices(&deviceList);
	for (int i = 0; i < deviceList.getSize(); ++i){
		printf("Device \"%s\" already connected\n", deviceList[i].getUri());
	}

	rc = device.open(ANY_DEVICE);
	if (rc != STATUS_OK)	{
		printf("Couldn't open device\n%s\n", OpenNI::getExtendedError());
		return;
	}
	
	if (device.getSensorInfo(SENSOR_DEPTH) != NULL){
		rc = depthStream.create(device, SENSOR_DEPTH);
		if (rc != STATUS_OK){
			printf("Couldn't create depthStream stream\n%s\n", OpenNI::getExtendedError());
		}
	}
    
	rc = depthStream.start();
	if (rc != STATUS_OK){
		printf("Couldn't start the depthStream stream\n%s\n", OpenNI::getExtendedError());
	}
    newFrame = 0;
    fetched = 1;

	// Register to new frame
	depthStream.addNewFrameListener(&depthPrinter);
    run = true;
	printf("Init done\n");

}
void terminateNI(){
	
	OpenNI::removeDeviceConnectedListener(&devicePrinter);
	OpenNI::removeDeviceDisconnectedListener(&devicePrinter);
	OpenNI::removeDeviceStateChangedListener(&devicePrinter);
    run = false;
	depthPrinter.destroy();
	depthStream.removeNewFrameListener(&depthPrinter);
	depthStream.stop();
	depthStream.destroy();
	device.close();
	OpenNI::shutdown();
	printf("Terminating\n");
	
}
}
