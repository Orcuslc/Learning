function [ root ] = newton_iter( func1, func2, x0, tol, order )
% Extract root ROOT of function FUNC1 with its derivative FUNC2 and
% init point X0 given

if nargin < 3
    error('More arguments are needed --newton_iter');
elseif nargin == 3
    tol = 1e-6;
    order = 100;
elseif nargin == 4
    order = 100;
end

count = 0;
while 1
    count = count + 1;
    f1 = feval(func1, x0);
    f2 = feval(func2, x0);
    x1 = x0 - f1 / f2;
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

