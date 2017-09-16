function [root, index, iteration, error, count] = bisection(f, a, b, tol)
% Bisection for root finding;
% f: the function to find root;
% [a, b]: the interval which root lies in; f(a)*f(b) < 0;
% tol: tolerance;
if(feval(f, a)*feval(f, b) > 0)
    error('Sign of value on edges of interval shoule be differernt');
end
count = 0; index = (0:1:100)';
iteration = zeros(100, 1);
error = zeros(100, 1);
while(1)
    count = count + 1;
    root = (a+b)/2;
    iteration(count) = root;
%     error(count) = abs(feval(f, root));
    error(count) = abs(b-root);
    if(b-root < tol) 
        return;
    elseif(count > 100) 
        warning('Count over 100, might not converge');
        return;
    end
    if(feval(f, b)*feval(f, root) <= 0)
        a = root;
    else
        b = root;
    end
end
    