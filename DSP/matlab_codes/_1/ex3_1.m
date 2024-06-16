% 清除当前图形窗口中的所有图形对象
clf;

% 定义延迟长度
D = 20;

% 定义时间序列n1，从0到299
n1 = 0:299;

% 定义延迟后的时间序列n2，长度比n1多D
n2 = 0:(n1(end) + D);

% 定义输入信号x，由两个不同频率的余弦波组成
x = cos((20/256) * pi * n1) + cos((200/256) * pi * n1);

% 将输入信号x延迟D个样本，前面补D个零
xd = [zeros(1, D) x];

% 定义滤波器的分子系数
num1 = [0.45 0.5 0.45];

% 定义滤波器的分母系数
den1 = [1 -0.53 0.46];

% 定义初始条件，初始状态为零
ic = [0 0];

% 通过滤波器处理输入信号x，得到输出信号y
y = filter(num1, den1, x, ic);

% 通过滤波器处理延迟后的输入信号xd，得到输出信号yd
yd = filter(num1, den1, xd, ic);

% 计算输出信号的长度
N = length(y);

% 计算y与yd的差值，yd的索引从1+D开始
d = y - yd(1 + D:N + D);

% 创建一个3行1列的子图区域，并绘制第一个子图
subplot(3, 1, 1);
% 在第一个子图中绘制滤波器输出信号y的离散图形
stem(n1, y);
% 设置第一个子图的标题
title('y[n]');
% 为第一个子图添加网格线
grid;

% 绘制第二个子图
subplot(3, 1, 2);
% 在第二个子图中绘制延迟后的滤波器输出信号yd的离散图形
stem(n2, yd(1:length(yd)));
% 设置第二个子图的标题
title('y[n-D]');

% 创建并绘制第三个子图
subplot(3, 1, 3);
% 在第三个子图中绘制y和yd差值的离散图形
stem(n1, d);
% 设置第三个子图的标题
title('差值');
% 为第三个子图添加网格线
grid;