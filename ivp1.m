image=imread("catto.jpg");
imshow(image);
z=double(image);
[row col]=size(image);
for i=1:1:row
    for j=1:1:col
        if ((z(i,j)>50)&&(z(i,j)<150));
z(i,j)=255;
else
z(i,j)=image(i,j); 
end 
end
end
subplot(2,1,1);
imshow(image);
title('original image');
subplot(2,1,2);
imshow(uint8(z));
title('Image after slicing')