clc; clear; close all; 
T = 0.001; fc =1/T; %抽样频率
ap=1; as=30; fp = 200; fs = 400; %数字滤波器的技术指标要求
wp = 2*pi*fp/fc; %数字滤波器通带截止频率
ws = 2*pi*fs/fc; %数字滤波器阻带截止频率

% 冲激响应不变法
%要求数字滤波器技术指标转化成模拟滤波器技术指标
WanpC = wp*fc; %通带截止频率
WansC = ws*fc; %阻带截止频率
%设计模拟滤波器阶数和截止频率
[NC,WancC]=buttord(WanpC,WansC,ap,as,'s');
[bC,aC]=butter(NC,WancC,'s'); %设计模拟滤波器系统函数Ha(s)
[BC,AC]=impinvar(bC,aC,fc); %用冲激响应不变法设计数字滤波器系统函数Hz
[HC,wC]=freqz(BC,AC,'whole'); %求数字滤波器的频率响应

% 双线性变换法
%要求数字滤波器技术指标转化成模拟滤波器技术指标
WanpS = 2*fc*tan(wp/2); %通带截止频率
WansS = 2*fc*tan(ws/2); %阻带截止频率
%设计模拟滤波器阶数和截止频率
[NS,WancS]=buttord(WanpS,WansS,ap,as,'s');
[bS,aS]=butter(NS,WancS,'s'); %设计模拟滤波器系统函数Ha(s)
[BS,AS]=bilinear(bS,aS,fc); %用双线性变换法设计数字滤波器系统函数Hz
[HS,wS]=freqz(BS,AS,'whole'); %求数字滤波器的频率响应

figure(1);
subplot(2,1,1);
plot(wC*fc/2/pi,20*log10(abs(HC)));
xlabel('频率 Hz'); ylabel('幅值 (dB)');
title('冲激响应不变法设计的低通数字滤波器');

subplot(2,1,2);
plot(wS*fc/2/pi,20*log10(abs(HS)));
xlabel('频率 Hz'); ylabel('幅值 (dB)');
title('双线性变换法设计的低通数字滤波器');
 

