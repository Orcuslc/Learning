function [res] = prob20(x, y)
% Problem 20;
% To compute \lim_{p\to\infty}(x^p+y^p)^{1/p};
    p = 2.^(1:20);
    res = ((x.^p+y.^p).^(1./p))';