% 清除工作区中的所有变量，关闭所有图形窗口，清除命令行窗口
clear all; close all; clc

% 定义滤波器的分子系数
a = 1;

% 定义滤波器的分母系数
b = [1 -0.9];

% 创建第一个图形窗口
figure(1);

% 创建一个2行1列的子图区域，并绘制第一个子图
subplot(2, 1, 1);
% 绘制滤波器的零极点图
zplane(a, b);

% 计算系统的单位冲击响应
h = impz(a, b);

% 绘制第二个子图
subplot(2, 1, 2);
% 绘制系统单位冲击响应的离散图形
stem(h);
% 设置第二个子图的标题
title('系统单位冲击响应');
% 设置x轴标签
xlabel('n');
% 设置y轴标签
ylabel('h(n)');

% 创建第二个图形窗口
figure(2);

% 计算滤波器的频率响应
[H, W] = freqz(a, b);

% 创建一个2行1列的子图区域，并绘制第一个子图
subplot(2, 1, 1);
% 绘制幅度响应曲线
plot(W/pi, abs(H));
% 设置第一个子图的标题
title('幅度响应曲线');
% 添加网格线
grid on;
% 设置x轴标签
xlabel('\omega \times \pi');
% 设置y轴标签
ylabel('|H(e^{j\omega})|');

% 绘制第二个子图
subplot(2, 1, 2);
% 绘制相位响应曲线
plot(W/pi, angle(H));
% 设置第二个子图的标题
title('相位响应曲线');
% 设置x轴标签
xlabel('\omega \times \pi');
% 设置y轴标签
ylabel('相角');
% 添加网格线
grid on;
