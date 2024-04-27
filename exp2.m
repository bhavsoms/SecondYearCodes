clear all;
clc;
a=imread('pout.tif');
a=double(a);
big=max((max(a)));
[row,col]=size(a);
c=row*col;
h=zeros(1,300);
z=zeros(1,300);
for n=1:1:row
for m=1:1:col
if (a(n,m)==0)
a(n,m)=1;
end
end
end
for n=1:1:row
for m=1:1:col
t=a(n,m);
h(t)=h(t)+1;
end
end
pdf=h/c;
cdf(1)=pdf(1);
for x=2:1:big
cdf(x)=pdf(x)+cdf(x-1);
end
new=round(cdf*big);
new=new+1;
for p=1:1:row
for q=1:1:col
temp=a(p,q);
b(p,q)=new(temp);
t=b(p,q);
z(t)=z(t)+1;
end
end
b=b-1;
subplot(2,2,1)
imshow(uint8(a))
title('Original image')
subplot(2,2,2)
bar(h)
title('Histogram of original Image')
subplot(2,2,3)
imshow(uint8(b))
title('Equilized Image')
subplot(2,2,4)
bar(z)
title('Histogram of Equilized Image')