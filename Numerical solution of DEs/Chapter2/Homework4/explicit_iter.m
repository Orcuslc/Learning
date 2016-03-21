function [ t, u ] = explicit_iter( func, inteval, u1, delta_t )
% EXPLICIT_ITER Explicit Euler Iteration

t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros(1, n);

for i = 1 : n
    u(i) = u1;
    u1 = u1 + delta_t * feval(func, t(i), u(i));
end

