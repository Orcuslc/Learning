function [t, u] = modified_iter(func, inteval, u1, delta_t)
% MODIFIED_ITER Modified Euler Iteration

t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros(1, n);
f = @(u, u0, t, delta_t)(u - delta_t * feval(func, t, u) - u0);

for i = 1 : n - 1
    u(i) = u1;
    t_i = t(i + 1);
    u0 = u1;
    u1 = fsolve(@(u) f(u, u0, t_i, delta_t), 1);
    u1 = u0 + delta_t/2 * (feval(func, t(i), u0) + ...
        feval(func, t_i, u1));
end
u(n) = u1;

end