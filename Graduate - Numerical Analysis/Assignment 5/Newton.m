function [x, error, count] = Newton(f, F, x0, max_iter, tol)
% Newton's method for nonlinear system;
% f: the funtion to extract root;
% F: Jacobian of f;
% x0: initial guess;
% max_iter, tol: max iteration and tolerance;
count = 0;
x = zeros(100, 2);
error = zeros(100, 1);
while(1)
    count = count + 1;
    x(count,1:2) = x0;
    x1 = x0 - feval(F, x0)\feval(f, x0);
    error(count) = norm(x1-x0);
    if(error(count) < tol)
        return;
    elseif(count > max_iter)
        warning('Iteration count overflow, may not converge');
        return;
    end
    x0 = x1;
end