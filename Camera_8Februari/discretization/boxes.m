function [matrix, time] = boxes(it, interval)
 

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

% Room resolution 
ix = 51;
iy = 51;
iz = 51;
matrix = zeros(ix,iy,iz);

% Room dimensions 
xMin = -8;
xMax = 8;
yMin = -8;
yMax = 8;   
zMin = -8;
zMax = 8; 

xStep = (xMax-xMin)/ix;
yStep = (yMax-yMin)/iy;
zStep = (zMax-zMin)/iz;

a = 1;
for n = 1:it;
    D = imread(char(depth(n)));
    %I = imread(char(rgb(n)));
    
    D=double(D)/factor;
    [r,c] = size(D);
    
    R = quat2RM([q1(n) q2(n) q3(n) q4(n)]);    % Rotation
    t = [tx(n);ty(n);tz(n)];                 % Translation
    C = [R t; 0 0 0 1];                      % Camera matrix 
    C_t = M*C;                               % Transformed camera matrix
    
    tic;
    % For pixles in depth image
    for i = 1:interval:r                                         %row -> i,  col->j
        for j = 1:interval:c
            zz = D(i,j);
            if (zz > 0)    
                % Pinhole camera model
                Bx = ((j - cx)*zz/fx);
                By = ((i - cy)*zz/fy); % ((i - cy)*zz/fy); % Det ska vara ((i+cy)*zz/fy), det ar inget konstigt att negativa y-axeln pekar uppåt. Det
                Bz = zz;   % är ett högerortonomerat system där z+axeln pekar in i skärmen
                
                globals = C*[Bx;By;Bz;1];                 % To place coordinates in the world frame
                
                x = globals(1);
                y = globals(2);
                z = globals(3);

                matrix(round(x/xStep+ix/2+1),round(y/yStep+iy/2+1),round(z/zStep+iz/2+1)) = 1;      % FIX

              
            end
        end
    end
    time(a) = toc;
    a = a+1;
end

figure
[ix, iy, iz] = size(matrix);

    for xi = 1:ix
        for yi = 1:iy
            for zi = 1:iz
                if(matrix(xi,yi, zi)==1)
                    x = xStep*(xi-1-ix/2);
                    y = yStep*(yi-1-iy/2);
                    z = zStep*(zi-1-iz/2);
                     plot3(x, y, z, 'r*')
                     hold on;
                end
            end
        end

    end
    grid on;    
    xlabel('x  index ')
    ylabel('y index')
    zlabel('z index')
    title('')
    shg
end