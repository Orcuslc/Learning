% Homework 4-3
clear all;
format long;
a = -2;
func = @(t, u)(a .* u);
u0 = 1;
u1 = -1;
delta_t = 1/8;
inteval = [0, 3];
op = {'explicit', 'implicit', 'modified', 'revised'};
symbol = {'*-', '.-', 'd-', 'o-'};

figure(1);
for i = 1:4
    [t, u] = Euler_iter(func, inteval, u0, delta_t, char(op(i)));
    [t2, u2] = Euler_iter(func, inteval, u1, delta_t, char(op(i)));
    plot(t, u, cell2mat(symbol(i)));
    hold on;
    plot(t2, u2, cell2mat(symbol(i)));
    hold on;
end

exact_func = @(x, u0)(exp(a .* x + log(u0)));
exact_value1 = feval(exact_func, t, u0);
exact_value2 = feval(exact_func, t, u1);
plot(t, exact_value1, 'x-');
hold on;
plot(t, exact_value2, 'x-');
legend('Explicit1', 'Explicit2', 'Implicit1', 'Implicit2',...
    'Modified1', 'Modified2', 'Revised1', 'Revised2',...
    'Exact1', 'Exact2', 'Location', 'Best');
title('Solving ODE du/dt = a*u with Euler Iteration');
grid on;

figure(2);
m = 5;
error_list = zeros(4, m);
for j = 1:m
    delta_t = 2 ^ (-j - 2);
    t = inteval(1):delta_t:inteval(2);
    exact_value = feval(exact_func, t, u0);
    for i = 1:4
        [t, u] = Euler_iter(func, inteval, u0, delta_t, char(op(i)));
        error_list(i, j) = max(abs(u - exact_value));
    end
end
for i = 1 : 4
    loglog(2 .^ (-3:-1:-m-2), error_list(i, :), cell2mat(symbol(i)));
    hold on;
end
legend('Explicit', 'Implicit', ...
    'Modified', 'Revised', ...
    'Location', 'Best');
title('Error of Euler iterations of solving du/dt = a*u');
grid on;