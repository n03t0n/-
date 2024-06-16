clc; clear; close all; 
xn=[2, 1, 3, 9, 0, 5, 7, 8];
N = length(xn);
Xk1 = fft(xn);
Xk2 = ditfft(xn,N);
Xk3 = ditfft(xn,N);
figure(1);
subplot(2,1,1); stem(0:N-1,real(Xk1),'fill','b','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Real part of Xk1'); 
subplot(2,1,2); stem(0:N-1,real(Xk2),'fill','r','linewidth',1.0);
xlabel('\itn'); ylabel('Amplitude'); title('Real part of Xk2'); 

