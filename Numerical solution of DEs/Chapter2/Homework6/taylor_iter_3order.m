function [t, u] = taylor_iter_3order(func, F, G, inteval, u1, delta_t)
%TAYLOR_ITER_3ORDER The 3rd-order taylor iteration

t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros(1, n);

for i = 1:n
    u(i) = u1;
    delta1 = feval(func, t(i), u(i)) + feval(F, t(i), u(i))*delta_t/2;
    delta2 = feval(G, t(i), u(i))*(delta_t^2)/6;
    u1 = u1 + (delta1 + delta2) * delta_t;
end

