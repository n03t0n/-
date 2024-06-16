f1 = 2;
f2 = 2.02;
f3 = 2.07;

t = 0:0.1:25.6;
N = 257;
f = t / N * 100;

x = sin(2 * pi * f1 * t) + sin(2 * pi * f2 * t) + sin(2 * pi * f3 * t);
X = fft(x);

subplot(2, 1, 1);
plot(t, x);
xlabel('n');
ylabel('x(n)');

subplot(2, 1, 2);
plot(f, abs(X));
ylabel('|x_{10}(k)|');
xlabel('f');
grid on;
