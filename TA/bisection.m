function [iteration] = bisection(f, a, b, maxiter)
% Bisection for root finding;
% f: the function to find root;
% [a, b]: the interval which root lies in; f(a)*f(b) < 0;
% tol: tolerance;
count = 0; 
iteration = zeros(maxiter, 1);
while(count < maxiter)
    count = count + 1;
    root = (a+b)/2;
    iteration(count) = root;
    if(feval(f, b)*feval(f, root) <= 0)
        a = root;
    else
        b = root;
    end
end
    