function [y,n] = seqadd(x1,n1,x2,n2)
%SEQADD 此处显示有关此函数的摘要
%   此处显示详细说明
n = min(min(n1), min(n2)):max(max(n1),max(n2));
y1 = zeros(1, length(h));
y2 = y1;

y1((n>=min(n1))&(n<=max(n1)))=x1;
y2((n>=min(n2))&(n<=max(n2)))=x2;

y=y1 + y2;
end

