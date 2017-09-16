function [root, index, iteration, error, count] = newton(f, df, x0, tol)
% Newton's Method for root extraction;
% f, df: function and it's derivative;
% x0: initial point;
% tol: tolerance;
count = 1; index = (0:1:100)';
iteration = zeros(100, 1); iteration(1) = x0;
error = zeros(100, 1); error(1) = abs(x0);
while(1)
    count = count + 1;
    x1 = x0 - feval(f, x0) / feval(df, x0);
    iteration(count) = x1;
    error(count) = abs(x1-x0);
    if(abs(x1-x0) < tol)
        root = x1;
        return;
    elseif(count > 100)
        warning('Count over 100, may not be convergence');
        root = x1;
        return;
    end
    x0 = x1;
end