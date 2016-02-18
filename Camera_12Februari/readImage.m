function D = readImage()
persistent it depth;
factor = 1000;
if(isempty(it))
    it = 1;
    [ts, tx, ty, tz, q1, q2,q3,q4, tp, rgb, tp, depth] = textread('associated.txt','%s %f %f %f %f %f %f %f %s %s %s %s');
else
    it = it +1;
end
if(it > length(depth))
    it = length(depth);
end
n = it;
D = imread(char(depth(n)));
D=double(D)/factor;

end