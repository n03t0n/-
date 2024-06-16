clc; clear; close all;

x1 = [2,1,1,2];
x2 = [1,-1,-1,1];
N1 = 5;
N2 = 7;
N3 = 8;

y1 = circonvtim(x1, x2, N1);
y2 = circonvtim(x1, x2, N2);
y3 = circonvtim(x1, x2, N3);
y4 = conv(x1, x2);

figure(1);

subplot(4,1,1);
stem(y1,'fill','g','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_1({\itn})');
title('{\ity}_1({\itn})={\itx}_1({\itn}) ④{\itx}_2({\itn})'); 

subplot(4,1,2);
stem(y2,'fill','b','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_2({\itn})');
title('{\ity}_2({\itn})={\itx}_1({\itn}) ⑦{\itx}_2({\itn})'); 

subplot(4,1,3);
stem(y3,'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_3({\itn})');
title('{\ity}_3({\itn})={\itx}_1({\itn}) ⑧{\itx}_2({\itn})');

subplot(4,1,4);
stem(y4,'fill','y','linewidth',1.0);
xlabel('\itn'); ylabel('{\ity}_4({\itn})');
title('{\ity}_4({\itn})={\itx}_1({\itn}) *{\itx}_2({\itn})');
