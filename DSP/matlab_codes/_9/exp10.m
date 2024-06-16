clc;clear all;close all;
fc=4000;
ap=0.5;as=40;fp=800;fs=1000;
wp=2*pi*fp/fc;
ws=2*pi*fs/fc;
N_t=2*pi/(ws-wp);%20
N=21;
wc=(ws+wp)/2;
N_c=wc/2/pi*21;%4.725
a=(N-1)/2;
k=0:floor((N-1)/2);
k2=floor((N-1)/2)+1:N-1;
angH=[-a*(2*pi)/N*k,a*(2*pi)/N*(N-k2)];
%未插入过渡点
Hrs=[ones(1,5),zeros(1,12),ones(1,4)];
Hb=Hrs.*exp(j*angH);
h=real(ifft(Hb,N));
[Hb,w]=freqz(h,1,1000);
mag=abs(Hb);
Hdb=20*log10(mag); 
%插入一个过渡点
Hrs1=[ones(1,5),0.6,zeros(1,10),0.6,ones(1,4)];
Hb1=Hrs1.*exp(j*angH);
hbl=real(ifft(Hb1,N));
[Hb1,w1]=freqz(hbl,1,1000);
mag1=abs(Hb1);
Hdb1=20*log10(mag1) ;
%插入两个过渡点
Hrs2=[ones(1,5),0.7,0.3,zeros(1,8),0.3,0.7,ones(1,4)];
Hb2=Hrs2.*exp(j*angH);
hb2=real(ifft(Hb2,N));
[Hb2,w2]=freqz(hb2,1,1000);
mag2=abs(Hb2);
Hdb2=20*log10(mag2) ;
figure(1);
plot(w/pi,Hdb,'m'); 
grid on; hold on;
plot(w1/pi,Hdb1,'c') ; 
hold on;
plot(w2/pi,Hdb2,'y') ; 
hold off;
xlabel('\omega/pi') ; 
ylabel('幅度(dB)') ;
title('滤波器幅频响应曲线');
legend('未插入过渡点','插入1个过渡点','插入2个过渡点');
 


