clear ;clc;close all
n=0:200;
x=n;
h=[1,0,3,7];
L=5;
ya=overadddft(x,h,L);
stem(0:length(ya)-1,real(ya));
title('重叠相加法overaddfft()计算线性卷积');
