function [root] = secant(f, x0, x1, tol)
% Secant Method for root extraction;
% f: the function;
% x0, x1: initial points;
% tol: tolerance;
count = 0;
while(1)
    count = count + 1;
    f0 = feval(f, x0);
    f1 = feval(f, x1);
    x2 = x1 - (x1 - x0)/(f1 - f0) * f1;
    if abs(x2 - x0) < tol
        disp(count);
        root = x2;
        return
    elseif count > 100
        warning('Count over 100, may not be convergence');
        root = x2;
        return
    end
    x0 = x1;
    x1 = x2;
end    