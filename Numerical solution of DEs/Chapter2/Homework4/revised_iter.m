function [t, u] = revised_iter(func, inteval, u1, delta_t)
% REVISED_ITER Revised Euler Iteration
t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros (1, n);

for i = 1:n - 1 
    u( i ) = u1;
    u_half = delta_t * feval(func ,t(i), u(i)) / 2 + u1;
    t_half = (t(i) + t(i + 1))/2;
    u1 = u1 + delta_t * feval (func, t_half, u_half);
end
u(n) = u1;
end
