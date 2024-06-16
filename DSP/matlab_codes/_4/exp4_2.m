clc; clear; close all;

x1 = [2, 1, 1, 2];
x2 = [1, -1, -1, 1];
ylin = conv(x1, x2);

figure(1);
stem(ylin, 'fill', 'r', 'linewidth', 1.0);
xlabel('\itn'); ylabel('{\ity}({\itn})');
title('{\ity}({\itn})={\itx}_1({\itn})*{\itx}_2({\itn})');
