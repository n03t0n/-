function [x,n] = impseq(np,ns,nf)
if((np<ns) || (np>nf) || (ns>nf))
    error('必须满足ns<=np<=nf')
end
n = ns:nf;
x = ((n-np)==0);
end


