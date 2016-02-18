function time = SDF(it)
%Ändra här så att matlab hittar din dataset
addpath('C:\Users\Sara\Desktop\Master theisis - Combine\dev\Kinect_matlab_SDK\rgbd_dataset_freiburg1_teddy');
%addpath('C:\Users\Sara\Desktop\Master theisis - Combine\dev\Path planning');
addpath('C:\Users\Sara\Desktop\Master theisis - Combine\dev\Kinect_matlab_SDK\rgbd_dataset_freiburg1_teddy\depth')
addpath('C:\Users\Sara\Desktop\Master theisis - Combine\dev\Kinect_matlab_SDK\rgbd_dataset_freiburg1_teddy\rgb')
[ts, tx, ty, tz, q1, q2,q3,q4, ts, rgb, ts, depth] = textread('associated.txt','%s %f %f %f %f %f %f %f %s %s %s %s');

factor = 5000;
fx = 525; % focal lengths
fy = 525;
cx = 319.5; % center pixels for the image. These parameters depends on the size of the image. 
cy = 239.5; % 319.5 and 239.5 are for 640x480 depth images

% Room resolution 
ix = 51;
iy = 51;
iz = 51;
matrix = zeros(ix,iy,iz);

% Room dimensions 
xMin = -3;
xMax = 3;
yMin = -2;
yMax = 2;   
zMin = -4;
zMax = 4;

% Image dimensions
px = 640;
py = 480;

% Global coordinates based on matrix resolution and room dimensions.
VX = xMin:abs(xMax-xMin)/(ix-1):xMax;
VY = yMin:abs(yMax-yMin)/(iy-1):yMax;
VZ = zMin:abs(zMax-zMin)/(iz-1):zMax;

R = quat2RM([q1(1) q2(1) q3(1) q4(1)]);    % Rotation
t = [tx(1);ty(1);tz(1)];                 % Translation
C1 = [R t; 0 0 0 1];                     % Camera matrix

% We want to find a matrix M so that M*C1=I
M = eye(4)/C1;

a = 1;

%%
for n =  1:it;
    D = imread(char(depth(n)));
    %I = imread(char(rgb(n)));   % For debug use
    D=double(D)/factor;
    
    % Calculate camera matrix
    R = quat2RM([q1(n) q2(n) q3(n) q4(n)]);  % Rotation
    t = [tx(n);ty(n);tz(n)];                 % Translationz
    C = [R t; 0 0 0 1];                      % Camera matrix 
    C_t = M*C;                               % Transformed camera matrix
    
    tic;
    % For all voxels in voxelgrid
    for i = 1:ix                                         
        for j = 1:iy
            for k = 1:iz
                % Use transformed camera matrix to go from global to local
                % coordinates and center round origo
                nn = C_t\[ VX(i); VY(j); VZ(k);1];
                vx = nn(1);
                vy = nn(2);
                vz = nn(3);
                 if(vz >=0)
                    %project voxel grid on image plane
                    lx = round(fx*vx/vz + cx);
                    ly = round(fy*vy/vz + cy);
                    
                    % Check if index is inside image range 
                    if(0< lx && lx <= px && 0< ly && ly <= py)
                        % Calculate singed distance by using distance between
                        % local voxel coordinates and local surface coordinates
                        sd = vz - D(ly,lx);
                        % If sd is less than zero voxel is in front of the surface else surface is in front of voxel so voxel should be marked as occupied. 
                        if(sd >= 0)
                            matrix(i,j,k) = 1;
                        else
                            matrix(i,j,k) = 0;
                        end
                    end
                end
            end
        end    
    end
    time(a) = toc;
    a = a+1;
end

% figure
%     for i = 1:ix
%         for j = 1:iy
%             for k = 1:iz
%                 if(matrix(i,j,k)==1)
%                     plot3(VX(i), VY(j), VZ(k), 'r*')
%                     hold on;
%                 end
%             end
%         end
%     end
%     grid on;    
%     xlabel('x ')
%     ylabel('y ')
%     zlabel('z ')
%     title('')
%     shg
end
