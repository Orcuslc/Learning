function [ root ] = secant_iter( func, x0, x1, tol, order )
% Extract root ROOT of function FUNC with init points X0, X1 given using
% secant iteration

if nargin < 3
    error('More arguments are needed --secant_iter');
elseif nargin == 3
    tol = 1e-6;
    order = 100;
elseif nargin == 4
    order = 100;
end

count = 0;
while 1
    count = count + 1;
    f0 = feval(func, x0);
    f1 = feval(func, x1);
    x2 = x1 - (x1 - x0)/(f1 - f0) * f1;
    if abs(x2 - x0) < tol
        disp(count);
        root = x2;
        return
    elseif count >= order
        root = x2;
        return
    elseif count > 100
        warning('Count over 100, may not be convergence');
        root = x2;
        return
    end
    x0 =x1;
    x1= x2;
end

end

