#include "wrapper.h"
#include "NI.h"

void asusInit(){
   initNI();
}
void asusCapture(uint16_T* depth){
    captureNI(depth);
}
void asusTerminate(){
    terminateNI();
}