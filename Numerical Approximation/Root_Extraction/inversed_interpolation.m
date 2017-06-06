function [ root ] = inversed_interpolation(func, a, b, tol)
% Extract root of function FUNC with init points A and B given

if nargin <= 2
    error('More args are needed --inversed interpolation');
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
        error('Values of function on init points do not have a opposite sign --inversed interpolation');
    end
end

count = 0;

while 1
    count = count + 1;
    fa = feval(func, a);
    fb = feval(func, b);
    x = (a*fb - b*fa)/(fb -fa);
    fx = feval(func, x);
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
        continue
    else
        a = x;
        continue
    end
end

