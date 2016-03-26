function [t, u] = Kutta_2order(func, inteval, u1, delta_t)
% Kutta_2order The 2nd-order Runge-Kutta iteration

t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros(1, n);

for i = 1:n
    u(i) = u1;
    delta1 = u(i) + delta_t * feval(func, t(i), u(i));
    delta2 = feval(func, t(i) + delta_t, delta1);
    u1 = u1 + delta_t / 2 * (feval(func, t(i), u(i)) + delta2);
end

