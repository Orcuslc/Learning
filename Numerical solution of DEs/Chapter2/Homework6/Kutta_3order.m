function [t, u] = Kutta_3order(func, inteval, u1, delta_t)
% Kutta_3order The 3rd-order Runge-Kutta iteration

t = inteval(1):delta_t:inteval(2);
n = length(t);
u = zeros(1, n);

for i = 1:n
    u(i) = u1;
    delta1 = feval(func, t(i), u(i));
    delta2 = feval(func, t(i)+delta_t/2, u(i)+delta_t/2*delta1);
    delta3 = feval(func, t(i)+delta_t, u(i)-delta_t*delta1+2*delta_t*delta2);
    u1 = u1 + delta_t/6*(delta1 + 4*delta2 + delta3);
end

