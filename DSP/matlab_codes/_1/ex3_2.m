% 清除当前图形窗口中的所有图形对象
clf;

% 定义混合信号的权重系数
a = 2;
b = 3;

% 定义时间序列n，从0到299
n = 0:299;

% 定义滤波器的分子系数
num = [0.45 0.5 0.45];

% 定义滤波器的分母系数
den = [1 -0.53 0.46];

% 定义输入信号1，由两个不同频率的余弦波组成
input_1 = cos((20/256) * pi * n) + cos((200/256) * pi * n);

% 定义输入信号2，由另外两个不同频率的余弦波组成
input_2 = cos((26/256) * pi * n) + cos((150/256) * pi * n);

% 定义混合输入信号，由输入信号1和信号2按权重系数a和b相加得到
input_mix = a * input_1 + b * input_2;

% 通过滤波器处理输入信号1，得到输出信号
output_of_input_1 = filter(num, den, input_1);

% 通过滤波器处理输入信号2，得到输出信号
output_of_input_2 = filter(num, den, input_2);

% 通过滤波器处理混合输入信号，得到输出信号
output_of_input_mix = filter(num, den, input_mix);

% 将处理后的输入信号1和信号2按权重系数a和b相加，得到混合输出信号
output_mix_of_1_2 = a * output_of_input_1 + b * output_of_input_2;

% 计算通过滤波器处理的混合信号与混合处理的输出信号之间的差值
d = output_of_input_mix - output_mix_of_1_2;

% 创建一个3行1列的子图区域，并绘制第一个子图
subplot(3, 1, 1);
% 在第一个子图中绘制通过滤波器处理的混合信号的离散图形
stem(n, output_of_input_mix);
% 设置第一个子图的标题
title('input-mix');

% 创建并绘制第二个子图
subplot(3, 1, 2);
% 在第二个子图中绘制混合处理的输出信号的离散图形
stem(n, output_mix_of_1_2);
% 设置第二个子图的标题
title('output-mix');

% 创建并绘制第三个子图
subplot(3, 1, 3);
% 在第三个子图中绘制两者之间差值的离散图形
stem(n, d);
% 设置第三个子图的标题
title('差值');
% 设置第三个子图的坐标轴范围
axis([0 300 -1 1]);
% 为第三个子图添加网格线
grid;
