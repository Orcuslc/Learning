function [In] = simpson(f, a, b, n)
% composite simpson rule;
% f: the function to integrate
% [a, b]: the integral interval
% n: the number of subintervals
h = (b-a)/n;
x = a:h:b;
fx = feval(f, x);
In = (2*sum(fx(1:2:end))+4*sum(fx(2:2:end))-fx(1)-fx(end))*h/3;
