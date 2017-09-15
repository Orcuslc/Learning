function [root, index, iteration, error] = newton(f, df, x0, tol)
% Newton's Method for root extraction;
% f, df: function and it's derivative;
% x0: initial point;
% tol: tolerance;
count = 1;
iteration = zeros(100, 1);
index = (0:1:100)';
error = zeros(100, 1);
iteration(1) = x0;
error(1) = feval(f, x0);
while(1)
    count = count + 1;
    x1 = x0 - feval(f, x0) / feval(df, x0);
    iteration(count) = x1;
    error(count) = feval(f, x1);
    if(abs(x1 - x0) < tol)
        root = x1;
        return;
    elseif(count > 100)
        warning('Count over 100, may not be convergence');
        root = x1;
        return;
    end
    x0 =x1;
end