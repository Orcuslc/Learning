function [ root ] = fixed_point_iter( func, x0, tol )
% FIXED_POINT_ITER Extract root ROOT of function FUNC with init point X0
% given using fixed point iteration
if nargin < 2
    error('More args are needed --fixed_point_iter');
elseif nargin == 2
    tol = 1e-6;
end

count = 0;
while 1
    count = count + 1;
    x1 = feval(func, x0);
    if count == 10
        disp(x1)
    end
    if abs(x1 - x0) < tol
        root = x1;
        return
    elseif count > 100
        warning('Count over 100, may not be convergence');
        root = x1;
        return
    end
    x0 = x1;
end

