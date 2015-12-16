function [ root ] = dichotomy( func, a, b, tol )
% Extract root of function FUNC with init points A, B given.

if nargin <= 2
    error('More args are needed --dichotomy');
elseif nargin == 3
    tol = 1e-6;
end

fa = feval(func, a);
fb = feval(func, b);
if fa == 0
    root = a;
    return
elseif fb == 0
    root = b;
    return
else
    if fa * fb > 0
        error('Values of function on init points do not have a opposite sign --dichotomy');
    end
end

count = 0;

while 1
    count = count + 1;
    x = (a+b)/2;
    fx = feval(func, x);
    fa = feval(func, a);
    if b - x < tol || abs(fx) < 1e-16
%         disp(count);
        root = x;
        return
    end
    
    if fx == 0
        root = x;
        return
    elseif fx * fa < 0
        b = x;
    else
        a = x;
    end
end

