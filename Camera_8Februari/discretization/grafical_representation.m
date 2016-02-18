%close all;
clear all;
%ƒndra h‰r sÂ att matlab hittar din dataset
addpath('C:\MT_Combine\dev\Development\Kinect\rgbd_dataset_freiburg1_teddy');
addpath('C:\MT_Combine\dev\Development\Kinect\rgbd_dataset_freiburg1_teddy\depth')
addpath('C:\MT_Combine\dev\Development\Kinect\rgbd_dataset_freiburg1_teddy\rgb')

% To get the depth values in meters, you have to scale with a factor of
% 5000 when the original file has uint16-format
factor = 5000;

fx = 525; % focal lengths
fy = 525;
% center pixels for the image:
cx = 319.5; % These parameters depends on the size of the image. 
cy = 239.5; % 319.5 and 239.5 are for 640x480 depth images



%Read samples
[ts, tx, ty, tz, q1, q2,q3,q4, ts, rgb, ts, depth] = textread('associated.txt','%s %f %f %f %f %f %f %f %s %s %s %s');

R = quat2RM([q1(1) q2(1) q3(1) q4(1)]);    % Rotation
t = [tx(1);ty(1);tz(1)];                 % Translation
C1 = [R t; 0 0 0 1];                     % Camera matrix

% We want to find a matrix M so that M*C1=I
M = eye(4)/C1;

number_samples = length(tx);
a = 1;

for n = 1:1400;
    n
    D = imread(char(depth(n)));
    I = imread(char(rgb(n)));
    
    D=double(D)/factor;
    [r,c] = size(D);
    
    R = quat2RM([q1(n) q2(n) q3(n) q4(n)]);    % Rotation
    t = [tx(n);ty(n);tz(n)];                 % Translation
    C = [R t; 0 0 0 1];                      % Camera matrix 
    C_t = M*C;                               % Transformed camera matrix
    
    % For pixles in depth image
    for i = 1:r                                         %row -> i,  col->j
        for j = 1:c
            zz = D(i,j);
            if (zz > 0)    
                % Pinhole camera model
                Bx = ((j - cx)*zz/fx);
                By = ((i - cy)*zz/fy); % ((i - cy)*zz/fy); % Det ska vara ((i+cy)*zz/fy), det ar inget konstigt att negativa y-axeln pekar upp√•t. Det
                Bz = zz;   % √§r ett h√∂gerortonomerat system d√§r z+axeln pekar in i sk√§rmen
                
                globals = C_t*[Bx;By;Bz;1];                 % To place coordinates in the world frame
                
                x(a) = globals(1);
                y(a) = globals(2);
                z(a) = globals(3);
                
                % Find the color of each coordinate
                R = double(I(i,j, 1))/256;
                G = double(I(i,j, 2))/256;
                B = double(I(i,j, 3))/256;
                color(a,:) = [R G B];

                a = a+1;
            end
        end
    end
end

figure
scatter3(x,y,z ,8,color);
%plot3(x,y,z, '.b')
grid on;
hold on;
shg
xlabel('x / m')
ylabel('y / m')
zlabel('z / m')
title('3D construction')





