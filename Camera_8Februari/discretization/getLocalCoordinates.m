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
                By = ((i - cy)*zz/fy); % ((i - cy)*zz/fy), det ar inget konstigt att negativa y-axeln pekar uppåt. Det
                Bz = zz;   % är ett högerortonomerat system där z+axeln pekar in i skärmen
                
                globals = [Bx;By;Bz;1];                 % To place coordinates in the world frame
                
                x(a) = globals(1);
                y(a) = globals(2);
                z(a) = globals(3);
               
                a = a+1;
              
            end
        end
 end
end
