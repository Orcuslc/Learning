function val = newton_poly(xx, fx, x)
% Newton Polynomial
% xx, fx: intepolation points, and function values;
% x: points for evaluating values;

% 1. get the coefficients of Newton Poly, 
%    the result saved in `fx`
n = length(xx);
for i=1:(n-1) 
    fx(i+1:n) = (fx(i+1:n)-fx(i:n-1))./(xx(i+1:n)-xx(i:n-1));
end

% 2. evaluate the function values with points given,
%    using Horner's method
val = fx(n);
for i=(n-1):-1:1
    val = val.*(x-xx(i))+fx(i);
end

