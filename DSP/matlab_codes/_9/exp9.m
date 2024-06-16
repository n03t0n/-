clear;clc;close all
fc=4000;
ap=0.5;as=40;fp=800;fs=1000;
wp=2*pi*fp/fc;
ws=2*pi*fs/fc;
dw=ws-wp;
wc=(wp+ws)/2;
N=8*pi/dw;%阶数
N2=12*pi/dw;
nd = (N-1)/2;
w = hann(N)';
for n=0:N-1;
hd(n+1)=sin(wc*(n-nd))/pi/(n-nd);
end
h1 = hd.*w;
H1=freqz(h1,1,512);
h2=fir1(N2-1,wc/pi,'low',blackman(N2));
H2=freqz(h2,1,512);
w=0:1/512:1-1/512;
figure(1);
H11=20*log10(abs(H1));
H22=20*log10(abs(H2));
v=plot(w,H11,w,H22,'r'); 
xlabel('\omega/\pi');ylabel('幅度(dB)');title('幅度特性')
hold on;
x1=wp/pi;x2=ws/pi;
y1=interp1(w,H11,x1);
y2=interp1(w,H11,x2);
y3=interp1(w,H22,x1);
y4=interp1(w,H22,x2);
plot(x1,y1,'-o');
plot(x2,y2,'-o');
plot(x1,y3,'-o');
plot(x2,y4,'-o');
legend(v,'汉宁窗','布莱克曼窗');
