function translation(it, rotate)
addpath('C:\MT_Combine\dev\Development\Kinect\rgbd_dataset_freiburg1_teddy');
addpath('C:\MT_Combine\dev\Development\Kinect\rgbd_dataset_freiburg1_teddy\depth');
interval = 1;
if(rotate)
    fileID = fopen('rotated.txt','w');
else
    fileID = fopen('not_rotated.txt','w');
end

% To get the depth values in meters, you have to scale with a factor of
% 5000 when the original file has uint16-format
factor = 5000;

global cx cy fx fy;
fx = 525; % focal lengths
fy = 525;
cx = 319.5; % These parameters depends on the size of the image. 
cy = 239.5; % 319.5 and 239.5 are for 640x480 depth images

%Read samples
[ts, tx, ty, tz, q1, q2,q3,q4, tp, rgb, tp, depth] = textread('associated.txt','%s %f %f %f %f %f %f %f %s %s %s %s');

%% First image
D = imread(char(depth(1))); 
D=double(D)/factor;
   
R = quat2RM([q1(1) q2(1) q3(1) q4(1)]);  % Rotation
t = [tx(1);ty(1);tz(1)];                 % Translation
C = [R t; 0 0 0 1];                     % Camera matrix

    
% For pixles in depth image
[x,y,z] = getLocalCoordinates(D, interval);
A = [x;y;z];
At = C*[A; ones(1,size(A,2))];
A = At(1:3, :);

fprintf(fileID,'%s %f %f %f %f %f %f %f %f', ts{1}, t(1), t(2), t(3), q1(1), q2(1), q3(1), q4(1) );
fprintf(fileID,'\n');

clear x y z;
t_old =  C(1:3,4);

%%
for n = 10:it
 n    
D = imread(char(depth(n))); 
D = double(D)/factor;
R = quat2RM([q1(n) q2(n) q3(n) q4(n)]);
%C = [R t_old; 0 0 0 1];
[x,y,z] = getLocalCoordinates(D, interval);
B_local = [x;y;z];
size(B_local);
Bt = C*[B_local; ones(1,size(B_local,2))];
B = Bt(1:3, :);
clear x y z
    
    
if(rotate)  
    [TR, TT] = icp(A, B,'Matching','kDtree','Minimize', 'plane');          %,'Matching','kDtree'
    R_diff = quat2RM([q1(n) q2(n) q3(n) q4(n)])/quat2RM([q1(n-1) q2(n-1) q3(n-1) q4(n-1)]);
    %TT = RBT(A,B);
    dt = [TR TT; 0 0 0 1];
    R = quat2RM([q1(n) q2(n) q3(n) q4(n)]);
    % Update camera matrix
    C = dt*C;
    
    t_tmp = C(1:3,4);
    C = [R t_tmp ; 0 0 0 1];
    
    % Transformed cloud
    Bt = C * [B_local; ones(1,size(B_local,2))];
    B = Bt(1:3, :);
    
else
    %[TR, TT] = icp(A, B ); %'Matching','kDtree', 'Minimize', 'point'
    TT = RBT(A,B)
    pause;
 %   R = quat2RM([q1(n) q2(n) q3(n) q4(n)]);
   % R_diff = quat2RM([q1(n) q2(n) q3(n) q4(n)])/quat2RM([q1(n-1) q2(n-1) q3(n-1) q4(n-1)]);
   % t = t_old + R_diff*TT;
    t = t_old + TT;
    % t = [tx(n);ty(n); tz(n)];
    % Update camera matrix
    C = [R t; 0 0 0 1];
    
    % Transformed cloud
    Bt = C * [B_local; ones(1,size(B_local,2))];
    B = Bt(1:3, :);
    
 end
%R = C(1:3, 1:3);
%R_error = quat2RM([q1(n) q2(n) q3(n) q4(n)])- R;
t =  C(1:3,4);
test(n,:) = t(: );
t_error(n-1,:) =  [tx(n);ty(n);tz(n)]-t;  

fprintf(fileID,'%s %f %f %f %f %f %f %f %f', ts{n}, t(1), t(2), t(3), q1(n), q2(n), q3(n),q4(n));
fprintf(fileID,'\n');


A = B; 
t_old = t;
clear x y z t B;
end

figure
plot(1:it-1, t_error(:,1), 'r')
hold on;
plot(1:it-1, t_error(:,2), 'b')
plot(1:it-1, t_error(:,3), 'g')
legend('x', 'y', 'z')
figure;
plot3(test(:,1), test(:,2), test(:,3), 'x')
hold on;
plot3(tx(1:it),ty(1:it), tz(1:it),'ro')

fclose(fileID);
end

function [x , y, z] = getLocalCoordinates(D, interval)
global cx cy fx fy
a = 1;
 [r,c] = size(D);
 for i = 1:interval:r                                         %row -> i,  col->j
        for j = 1:interval:c
            zz = D(i,j);
            if (zz > 0)    
                % Pinhole camera model
                Bx = ((j - cx)*zz/fx);
                By = ((i - cy)*zz/fy); 
                Bz = zz;  
                
                locals = [Bx;By;Bz;1];                 % To place coordinates in the local frame
                
                x(a) = locals(1);
                y(a) = locals(2);
                z(a) = locals(3);
               
                a = a+1;
              
            end
        end
 end
end

function t_diff = RBT(A,B)


centroid_A = [mean(A(1,:)); mean(A(2,:)); mean(A(3,:))]
centroid_B = [mean(B(1,:)); mean(B(2,:)); mean(B(3,:))]
pause;

% plot3(A(1,1:10:end),A(2,1:10:end), A(3,1:10:end),'bo');
% hold on
% plot3(B(1,1:10:end),B(2,1:10:end), B(3,1:10:end),'rx');
% plot3(centroid_A(1), centroid_A(2), centroid_A(3), 'g+');
% plot3(centroid_B(1), centroid_B(2), centroid_B(3), 'bl+');
% hold off
% pause;
t_diff =  -(centroid_B - centroid_A);
end

    