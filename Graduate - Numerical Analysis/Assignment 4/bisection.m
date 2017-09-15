function [root] = bisection(f, a, b, tol)
% Bisection for root finding;
% f: the function to find root;
% [a, b]: the interval which root lies in; f(a)*f(b) < 0;
% tol: tolerance;
if(feval(f, a)*feval(f, b) > 0)
    error('Sign of value on edges of interval shoule be differernt');
end
while(1)
    root = (a+b)/2;
    if(b-root < tol) 
        return;
    end
    if(feval(f, b)*feval(f, c) <= 0)
        a = root;
    else
        b = root;
    end
end
    