function R = quat2RM( Qrotation )
% from http://www.flipcode.com/documents/matrfaq.html#Q54

X = Qrotation( 1 );
Y = Qrotation( 2 );
Z = Qrotation( 3 );
W = Qrotation( 4 );

xx      = X * X;
xy      = X * Y;
xz      = X * Z;
xw      = X * W;

yy      = Y * Y;
yz      = Y * Z;
yw      = Y * W;

zz      = Z * Z;
zw      = Z * W;

R = zeros(3,3);
R(1,1)  = 1 - 2 * ( yy + zz );
R(1,2)  =     2 * ( xy - zw );
R(1,3)  =     2 * ( xz + yw );

R(2,1)  =     2 * ( xy + zw );
R(2,2)  = 1 - 2 * ( xx + zz );
R(2,3)  =     2 * ( yz - xw );

R(3,1)  =     2 * ( xz - yw );
R(3,2)  =     2 * ( yz + xw );
R(3,3) = 1 - 2 * ( xx + yy );
end