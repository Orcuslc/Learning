function [t, u] = taylor_iter_2order(func, F, inteval, u1, delta_t)
%TAYLOR_ITER_2ORDER The 2nd-order taylor iteration

t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros(1, n);

for i = 1:n
    u(i) = u1;
    delta = feval(func, t(i), u(i)) + feval(F, t(i), u(i))*delta_t/2;
    u1 = u1 + delta_t * delta;
end

