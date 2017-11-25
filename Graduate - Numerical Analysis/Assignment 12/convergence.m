function [Rn] = convergence(f, a, b, nmax, rule, f2)
% Compute the rate of convergence
n = 2.^(1:nmax+2);
In = zeros(nmax+2, 1);
if(nargin == 5)
    f2 = @(x) x;
end
if(strcmp(rule, 'trapezoidal'))
    for i = 1:nmax+2
        In(i) = trapezoidal(f, a, b, n(i));
    end
elseif(strcmp(rule, 'simpson'))
    for i = 1:nmax+2
        In(i) = simpson(f, a, b, n(i));
    end
elseif(strcmp(rule, 'corrected_trapezoidal'))
    for i = 1:nmax+2
        In(i) = corrected_trapezoidal(f, f2, a, b, n(i));
    end
end

Rn = (In(2:end-1)-In(1:end-2))./(In(3:end)-In(2:end-1));
