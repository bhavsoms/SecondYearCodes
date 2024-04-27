%Salt and pepper
clear all;
I=imread('cameraman.tif');
J=imnoise(I,'salt & pepper',0.02); %adding noise
a=double(J);
b=a;
aa = double(I);
c = aa;
[row,col]=size(a);
for x=2:1:row-1
for y=2:1:col-1
a1=[a(x-1,y-1) a(x-1,y) a(x-1,y+1) a(x,y-1) a(x,y) a(x,y+1) a(x+1,y-1) a(x+1,y) a(x+1,y+1)];
a2=sort(a1);
med=a2(5);
b(x,y)=med;
end
end
for x=2:1:row-1
for y=2:1:col-1
a1=[a(x-1,y-1) a(x-1,y) a(x-1,y+1) a(x,y-1) a(x,y) a(x,y+1) a(x+1,y-1) a(x+1,y) a(x+1,y+1)];
avg  = mean(a1);
c(x,y) = avg;
end
end
subplot(2,2,1)
imshow(uint8(J))
title("Salt & pepper Image")
subplot(2,2,2)
imshow(uint8(b))
title("Smoothened Image")
input image

%Avg Filter

% Read the image
I = imread('cameraman.tif');

% Create the average pass filter
apf = ones(3,3) / 9;

% Apply the average pass filter
I_apf = imfilter(I, apf);

% Display the images
figure(4);
subplot(2,2,3);
imshow(I);
title('Original Image');
subplot(2,2,4);
imshow(c);
title('Average Pass Filtered Image');
