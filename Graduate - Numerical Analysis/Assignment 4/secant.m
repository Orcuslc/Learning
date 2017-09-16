function [root, index, iteration, error, count] = secant(f, x0, x1, tol)
% Secant Method for root extraction;
% f: the function;
% x0, x1: initial points;
% tol: tolerance;
count = 2; index = (0:1:100)';
iteration = zeros(100, 1); iteration(1) = x0; iteration(2) = x1;
error = zeros(100, 1); error(1) = abs(x0); error(2) = abs(x1-x0);
while(1)
    count = count + 1;
    f0 = feval(f, x0);
    f1 = feval(f, x1);
    x2 = x1 - (x1 - x0)/(f1 - f0) * f1;
    iteration(count) = x2;
    error(count) = abs(x2-x1);
    if(abs(x2 - x0) < tol)
        root = x2;
        return;
    elseif(count > 100)
        warning('Count over 100, may not be convergence');
        root = x2;
        return;
    end
    x0 = x1;
    x1 = x2;
end    