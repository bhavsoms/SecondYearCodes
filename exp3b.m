% High Boost Filtering (Sharpening)
clear all;
% Read the image
aa = imread('cameraman.tif');
a = double(aa);
[row, col] = size(a);
% High Boost filter matrix
w = [-1 -1 -1; -1 8.9 -1; -1 -1 -1] / 9;
% Initialize the filtered image
a1 = zeros(row, col);
% Apply the high boost filter
for x = 2:row - 1
    for y = 2:col - 1
        a1(x, y) = w(1) * a(x - 1, y - 1) + w(2) * a(x - 1, y) + w(3) * a(x - 1, y + 1) + ...
                   w(4) * a(x, y - 1) + w(5) * a(x, y) + w(6) * a(x, y + 1) + ...
                   w(7) * a(x + 1, y - 1) + w(8) * a(x + 1, y) + w(9) * a(x + 1, y + 1);
    end
end
% Display original and high boost filtered images
subplot(2, 2, 1);
imshow(uint8(a));
title('Original Image');
subplot(2, 2, 2);
imshow(uint8(a1));
title('High Boost Filtered Image');
% High Pass Filtering (Image Enhancement)
clear all;
% Read the image
aa = imread('cameraman.tif');
a = double(aa);
[row, col] = size(a);
% High-pass filter kernel
kernel = [-1 -1 -1; -1 8 -1; -1 -1 -1];
% Initialize the filtered image
a_high_pass = zeros(row, col);
% Apply the high-pass filter
for x = 2:row - 1
    for y = 2:col - 1
        a_high_pass(x, y) = sum(sum(kernel .* a(x-1:x+1, y-1:y+1)));
    end
end
% Display original and high-pass filtered images
subplot(2, 2, 3);
imshow(uint8(a));
title('Original Image');
subplot(2, 2, 4);
imshow(uint8(a_high_pass));
title('High-Pass Filtered Image');