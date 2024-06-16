function y = overadddft(x,h,L)
M=length(h);
if L<M
    L=M+1;
end
N=M+L-1;%4+5-1=8
Lx=length(x);%201
T=ceil(Lx/L);
t=zeros(1,M-1);%41
x=[x,zeros(1,(T+1)*N-Lx)];
y=zeros(1,(T+1)*L);
for i=0:1:T
    xi=i*L+1;
    x_seg=x(xi:xi+L-1);
    y_seg=dftconv(x_seg,h,N);%N=8,length(x_seg)=5
    y_seg(1:M-1)=y_seg(1:M-1)+t(1:M-1);
    t(1:M-1)=y_seg(L+1:N);
    y(xi:xi+L-1)=y_seg(1:L);
end
y=y(1:Lx+M-1);
end