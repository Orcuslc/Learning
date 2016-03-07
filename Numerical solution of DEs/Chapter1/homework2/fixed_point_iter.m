function [ root, root_list ] = fixed_point_iter( func, x0, tol, order )
% FIXED_POINT_ITER Extract root ROOT of function FUNC with init point X0
% given using fixed point iteration
% author: chuanlu
% 2016-03-04

if nargin < 3
    error('More arguments are needed --newton_raphson_iter');
elseif nargin == 3
    tol = 1e-6;
    order = 100;
end

count = 0;
root_list = zeros(1, 1);
while 1
    count = count + 1;
    root_list(count) = x0;
    x1 = feval(func, x0);
    if abs(x1 - x0) < tol || count >= order
        root = x1;
        return
    elseif count >= 100
        warning('Count over 100, may not be convergence');
        root = x1;
        return
    end
    x0 = x1;
end

