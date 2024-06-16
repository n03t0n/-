clf;
N = 40;
n = 0:299;
x = cos((20/256) * pi * N) + cos((200/256) * pi * N);
num1 = [0.5 0.27 0.77];
num2 = [0.45 0.5 0.45];
den1 = 1;
den2 = [1 -0.53 0.46];
y1 = impz(num1, den1, N);
y2 = impz(num2, den2, N);

subplot(2, 1, 1);
stem(y1);
subplot(2, 1, 2);
stem(y2);
grid;