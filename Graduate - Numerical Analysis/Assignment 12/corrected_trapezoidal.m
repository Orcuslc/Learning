function [In] = corrected_trapezoidal(f, f2, a, b, n)
% composite corrected trapezoidal rule;
% f: the function to integrate; f2: derivative of f;
% [a, b]: the integral interval
% n: the number of subintervals
h = (b-a)/n;
x = a:h:b;
fx = feval(f, x);
In = (sum(fx)-fx(1)*0.5-fx(end)*0.5)*h...
    -(h^2)/12*(f2(b)-f2(a));