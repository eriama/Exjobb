%globals is a matrix
%globals(coordinates,distance,time)
%we want to know the coordinates of the point closest to the camera at
%time=t
%the distance 
close all
t=20;
%plockar ut coordinaterna vid tidpunkten t
x_cam=globals(1,:,t);
y_cam=globals(2,:,t);
z_cam=globals(3,:,t);
figure
plot3(x_cam, y_cam, z_cam, '.')
figure
plot(x_cam, -y_cam, '.')

k=1;
for i = 1 : length(z_cam)
    if(z_cam(i)~=0 && z_cam(i)<1.5)
        temp(k)=z_cam(i);
        x_new(k)=globals(1,i,t);
        y_new(k)=globals(2,i,t);
        z_new(k)=globals(3,i,t);
        k=k+1;
    end 
end
figure
plot(x_new, -y_new, '.')
figure
plot3(x_new, -y_new, z_new, '.')

for j = 1 : length(temp)
    if(temp(j)==min(temp))
        place_min=j;
    end
end

closest_dot = globals(:,place_min,t)
      
        
        
        
        
        
        