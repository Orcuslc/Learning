function [ root ] = simplified_newton_iter( func, x0, dfx0, tol, order )
% Extract root ROOT of function FUNC with its derv on x0 DFX0 given using
% newton iteration

if nargin < 3
    error('More arguments are needed --simplified_newton_iter');
elseif nargin == 3
    tol = 1e-6;
    order = 100;
elseif nargin == 4
    order = 100;
end

count = 0;
while 1
    count = count + 1;
    f1 = feval(func, x0);
    x1 = x0 - f1 / dfx0;
    if abs(x1 - x0) < tol
        disp(count);
        root = x1;
        return
    elseif count >= order
        root = x1;
        return
    elseif count > 100
        warning('Count over 100, may not be convergence');
        root = x1;
        return
    end
    x0 =x1;
end

