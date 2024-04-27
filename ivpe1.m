clc;
r=imread('cameraman.tif');
z=double(r);
[row col]=size(r);
for i=1:1:row
for j=1:1:col
if ((z(i,j)>50)&&(z(i,j)<150))
z(i,j)=255;
else
z(i,j)=r(i,j);
end
end
end
subplot(2,1,1);
imshow(r);
title('original image');
subplot(2,1,2);
imshow(uint8(z));
title('Image after slicing')