function boxes_translation_rec(it)

interval = 2;
fileID = fopen('trajectory.txt','w');



% To get the depth values in meters, you have to scale with a factor of
% 5000 when the original file has uint16-format
factor = 5000;

global cx cy fx fy;
fx = 525; % focal lengths
fy = 525;
% center pixels for the image:
cx = 319.5; % These parameters depends on the size of the image. 
cy = 239.5; % 319.5 and 239.5 are for 640x480 depth images

%Read samples
[ts, tx, ty, tz, q1, q2,q3,q4, tp, rgb, tp, depth] = textread('associated.txt','%s %f %f %f %f %f %f %f %s %s %s %s');

% Room resolution 
ix = 51;
iy = 51;
iz = 51;
matrix = zeros(ix,iy,iz);

xMin = -12;
xMax = 12;
yMin = -12;
yMax = 12;   
zMin = -12;
zMax = 12;   

xStep = (xMax-xMin)/ix;
yStep = (yMax-yMin)/iy;
zStep = (zMax-zMin)/iz;


%% First image
D = imread(char(depth(1))); 
D=double(D)/factor;
I = imread(char(rgb(1))); 

R = quat2RM([q1(1) q2(1) q3(1) q4(1)]);  % Rotation
t = [tx(1);ty(1);tz(1)];                 % Translation
C = [R t; 0 0 0 1];                     % Camera matrix

    
% For pixles in depth image
[x,y,z, color] = getLocalCoordinates(D, I,interval);
A = [x;y;z];
At = C * [A; ones(1,size(A,2))];
A = At(1:3, :);


%%
fprintf(fileID,'%s %f %f %f %f %f %f %f %f', ts{1}, t(1), t(2), t(3), q1(1), q2(1), q3(1), q4(1) );
fprintf(fileID,'\n');

clear x y z;

%%
for n = 2:it
 n    
D = imread(char(depth(n))); 
D=double(D)/factor;
I = imread(char(rgb(n))); 
[x,y,z, color] = getLocalCoordinates(D, I, interval);
B = [x;y;z];
Bt = C * [B; ones(1,size(B,2))];
B = Bt(1:3, :);
clear x y z
    
   
    
%[TR, TT] = icp(A, B,'Matching','kDtree', 'Minimize', 'point');          %,'Matching','kDtree'

R_diff = quat2RM([q1(n) q2(n) q3(n) q4(n)])/quat2RM([q1(n-1) q2(n-1) q3(n-1) q4(n-1)]);
TT = RBT(A,B);
dt = [R_diff TT; 0 0 0 1];

% Transformed cloud
Bt = dt * [B; ones(1,size(B,2))];
B = Bt(1:3, :);

% Update camera matrix
C = dt*C;
R = C(1:3, 1:3);
R_error = quat2RM([q1(n) q2(n) q3(n) q4(n)])- R;
t = C(1:3,4);
t_error(n-1,:) =  [tx(n);ty(n);tz(n)]-t;  
fprintf(fileID,'%s %f %f %f %f %f %f %f %f', ts{n}, t(1), t(2), t(3), q1(n), q2(n), q3(n),q4(n));
fprintf(fileID,'\n');



for a = 1:length(B)

   matrix(round(B(1,a)/xStep+ix/2+1),round(B(2,a)/yStep+iy/2+1),round(B(3,a)/zStep+iz/2+1))= 1;      % FIXA
end

A = B; 
clear x y z t B;
end

% %figure
% [ix, iy, iz] = size(matrix);
% 
%     for xi = 1:ix
%         for yi = 1:iy
%             for zi = 1:iz
%                 if(matrix(xi,yi, zi)==1)
%                     x = xStep*(xi-1-ix/2);
%                     y = yStep*(yi-1-iy/2);
%                     z = zStep*(zi-1-iz/2);
%                      plot3(x, y, z, 'b*')
%                      hold on;
%                 end
%             end
%         end
% 
%     end
%     grid on;    
%     xlabel('x  index ')
%     ylabel('y index')
%     zlabel('z index')
%     title('')
%     shg

figure(2)
plot(1:it-1, t_error(:,1), 'r')
hold on;
plot(1:it-1, t_error(:,2), 'b')
plot(1:it-1, t_error(:,3), 'g')
legend('x', 'y', 'z')

fclose(fileID);




end


function [x , y, z, color] = getLocalCoordinates(D, I, interval)
global cx cy fx fy
a = 1;
 [r,c] = size(D);
 for i = 1:interval:r                                         %row -> i,  col->j
        for j = 1:interval:c
            zz = D(i,j);
            if (zz > 0)    
                % Pinhole camera model
                Bx = ((j - cx)*zz/fx);
                By = ((i - cy)*zz/fy); % ((i - cy)*zz/fy), det ar inget konstigt att negativa y-axeln pekar uppåt. Det
                Bz = zz;   % är ett högerortonomerat system där z+axeln pekar in i skärmen
                
                globals = [Bx;By;Bz;1];                 % To place coordinates in the world frame
                
                x(a) = globals(1);
                y(a) = globals(2);
                z(a) = globals(3);
               
              
                R = double(I(i,j, 1))/256;
                G = double(I(i,j, 2))/256;
                B = double(I(i,j, 3))/256;
                color(a,:) = [R G B];
                
                
                a = a+1;
            end
        end
 end
end

function t_diff = RBT(A,B)
centroid_A = [mean(A(1,:)); mean(A(2,:)); mean(A(3,:))]';
centroid_B = [mean(B(1,:)); mean(B(2,:)); mean(B(3,:))]';

t_diff =  centroid_B' - centroid_A';

end
  