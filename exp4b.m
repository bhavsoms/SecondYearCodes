clear all;
clc;
aa=imread('cameraman.tif');
a=double(aa);
[r c]=size(a);
% prewits
w1=[-1 -1 -1; 0 0 0; 1 1 1];
w2=[-1 0 1; -1 0 1; -1 0 1];
% Sobel
w3=[-1 -2 -1; 0 0 0; 1 2 1];
w4=[-1 0 1; -2 0 2; -1 0 1];
% Roberts masks 
w5 = [1 0; 0 -1];  
w6 = [0 1; -1 0];

for x=2:r-1
    for y=2:c-1
        a1(x,y)=[w1(1)*a(x-1,y-1)+w1(2)*a(x-1,y)+w1(3)*a(x-1,y+1)+w1(4)*a(x,y-1)+w1(5)*a(x,y)+w1(6)*a(x,y+1)+w1(7)*a(x+1,y-1)+w1(8)*a(x+1,y)+w1(9)*a(x+1,y+1)];
        a2(x,y)=[w2(1)*a(x-1,y-1)+w2(2)*a(x-1,y)+w2(3)*a(x-1,y+1)+w2(4)*a(x,y-1)+w2(5)*a(x,y)+w2(6)*a(x,y+1)+w2(7)*a(x+1,y-1)+w2(8)*a(x+1,y)+w2(9)*a(x+1,y+1)];
        a3(x,y)=[w3(1)*a(x-1,y-1)+w3(2)*a(x-1,y)+w3(3)*a(x-1,y+1)+w3(4)*a(x,y-1)+w3(5)*a(x,y)+w3(6)*a(x,y+1)+w3(7)*a(x+1,y-1)+w3(8)*a(x+1,y)+w3(9)*a(x+1,y+1)];
        a4(x,y)=[w4(1)*a(x-1,y-1)+w4(2)*a(x-1,y)+w4(3)*a(x-1,y+1)+w4(4)*a(x,y-1)+w4(5)*a(x,y)+w4(6)*a(x,y+1)+w4(7)*a(x+1,y-1)+w4(8)*a(x+1,y)+w4(9)*a(x+1,y+1)];
        a5(x,y)=[w5(1)*a(x,y)+w5(2)*a(x,y+1)+w5(3)*a(x+1,y)+w5(4)*a(x+1,y+1)];
        a6(x,y)=[w6(1)*a(x,y)+w6(2)*a(x,y+1)+w6(3)*a(x+1,y)+w6(4)*a(x+1,y+1)];
    end
end
a7=abs(a1)+abs(a2);
a8=abs(a3)+abs(a4);
a9=abs(a5)+abs(a6);
subplot(3,3,2);
imshow(aa);
title('original');
subplot(3,3,4);
imshow(uint8(a1));
title('Prewitts (x)');
subplot(3,3,5);
imshow(uint8(a3));
title('Prewitts (y)');
subplot(3,3,6);
imshow(uint8(a4));
title('Sobel (x)');
subplot(3,3,7);
imshow(uint8(a5));
title('Sobel (y)');
subplot(3,3,8);
imshow(uint8(a6));
title('Robert (x)');
subplot(3,3,9);
imshow(uint8(a7));
title('Robert (y)');
