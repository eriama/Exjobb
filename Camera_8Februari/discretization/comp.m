function timecomp
figure;
hold on;

iterations = 10;
%Run with every 5th pixel
intervall = 5;
[mat1, BOX_5_5] = boxes(iterations, intervall);
plot(1:length(BOX_5_5), BOX_5_5)

intervall = 1;
[mat2 BOX_1_1] = boxes(iterations, intervall);
plot(1:length(BOX_1_1), BOX_1_1, 'g')

sdf = SDF(iterations);
plot(1:length(sdf), sdf, 'r')

legend('Box 5.5', 'Box 1.1', 'SDF')
end
%%
function comp_matrix()
clear all
it = 2;
intervall = 5;
[matrix, time] =boxes(it, intervall);
t_matrx = boxes_translation2;
matrix_error = matrix-t_matrx;


[ix, iy, iz] = size(matrix);

% Room dimensions 
xMin = -5;
xMax = 5;
yMin = -5;
yMax = 5;   
zMin = -5;
zMax = 5;

xStep = (xMax-xMin)/ix;
yStep = (yMax-yMin)/iy;
zStep = (zMax-zMin)/iz;

figure

    for xi = 1:ix
        for yi = 1:iy
            for zi = 1:iz
                if(matrix_error(xi,yi, zi)~=0)
                     x = xStep*(xi-1-ix/2);
                     y = yStep*(yi-1-iy/2);
                     z = zStep*(zi-1-iz/2);
                     plot3(x, y, z, 'g*')
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