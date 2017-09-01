function [res] = prob20revised(x, y)
% prob 20;
% revised the computation by 
% \lim_{p\to\infty} ((x/y)^p+1)^{1/p}*y
% where (x/y) < 1;
    p = 2.^(1:20);
    if(abs(x) < abs(y))
        res = ((x/y).^p+1).^(1./p)*y;
    else
        res = ((y/x).^p+1).^(1./p)*x;
    end
    res = res';
    