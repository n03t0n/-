function y=dftconv(x1,x2,N2)
Xk1=NDFTfor(x1,N2);
Xk2=NDFTfor(x2,N2);
YK=Xk1.*Xk2;
y=ifft(YK);
end