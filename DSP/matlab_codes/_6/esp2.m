clc; clear; close all; 
Xk=[36.0000, -4.0000+9.6569i, -4.0000+4.0000i, -4.0000+1.6569i, -4.0000, -4.0000-1.6569i, -4.0000-4.0000i, -4.0000-9.6569i];
N = length(Xk);

% 直接调用ifft函数计算Xk的离散傅里叶反变换
xn1 = ifft(Xk);

%利用fft函数和ditfft函数计算Xk的离散傅里叶反变换
Xk_conj = conj(Xk);
xn2 = conj(fft(Xk_conj))/N;
xn3 = conj(ditfft(Xk_conj, N))/N;
figure(1);
subplot(3,2,1); stem(0:N-1,real(xn1),'fill','b','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Real part of xn1'); 
subplot(3,2,2); stem(0:N-1,imag(xn1),'fill','b','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Imaginary part of xn1');
subplot(3,2,3); stem(0:N-1,real(xn2),'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Real part of xn2');
subplot(3,2,4); stem(0:N-1,imag(xn2),'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Imaginary part of xn2'); 
subplot(3,2,5); stem(0:N-1,real(xn3),'fill','g','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Real part of xn3');
subplot(3,2,6); stem(0:N-1,imag(xn3),'fill','g','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Imaginary part of xn3');

