function X = NDFTfor(xn,N)
X=zeros(1,N);
xn=[xn,zeros(1,N-length(xn))];
for k=0:N-1
    for n=0:N-1
        X(k+1)=X(k+1)+xn(n+1)*exp(-1i*2*pi*n*k/N);
    end
end
end