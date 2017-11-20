function [In] = trapezoidal(f, a, b, n)
% composite trapezoidal rule;
% f: the function to integrate
% [a, b]: the integral interval
% n: the number of subintervals
h = (b-a)/n;
x = a:h:b;
fx = feval(f, x);
In = (sum(fx)-fx(1)*0.5-fx(end)*0.5)*h;