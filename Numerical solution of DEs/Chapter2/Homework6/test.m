% Page 74, Exercise 1
% solve du/dt = u - u^2;

func = @(t, u)(u - u .^ 2);
u0 = 1.5;
ui = 0.5;
inteval = [0, 8];
delta_t = 1/8;

order1 = 1;
order2 = 2;
order3 = 3;
order4 = 4;

F = @(t, u)((1-2.*u).*(u-u.^2));
G = @(t, u)((u-u.^2).*(6*u.^2-6*u+1));

[t, u1] = Taylor_iter(func, inteval, u0, delta_t, order1);
plot(t, u1, '*-');
hold on

[t2, u2] = Taylor_iter(func, inteval, u0, delta_t, order2, F);
plot(t2, u2, '.-');
hold on

[t3, u3] = Taylor_iter(func, inteval, u0, delta_t, order3, F, G);
plot(t3, u3, 'd-');
hold on

exact_func = @(x, u0)(1 ./ ((1/u0 - 1) .* exp(-x) + 1));
exact_value = feval(exact_func, t, u0);
plot(t, exact_value, '-');
hold on

[t11, u11] = Taylor_iter(func, inteval, ui, delta_t, order1);
plot(t11, u11, '*-');
hold on

[t21, u21] = Taylor_iter(func, inteval, ui, delta_t, order2, F);
plot(t21, u21, '.-');
hold on

[t31, u31] = Taylor_iter(func, inteval, ui, delta_t, order3, F, G);
plot(t31, u31, 'd-');
hold on

exact_value1 = feval(exact_func, t, ui);
plot(t, exact_value1, '-');

legend('Explicit Euler', '2nd-order Taylor', '3rd-order Taylor',...
    'Exact', 'Explicit Euler2', '2nd-order Taylor2',...
    '3rd-order Taylor2', 'Exact2', 'Location', 'Best');
title({['Solving du/dt = u-u^2 using Explicit Euler and 2/3-order'];
       ['Taylor iteration']});
grid on;


% Page 79, Exercise 3
figure(2)
symbol = {'*-', '.-', 'd-', 'o-'};
m = 13;
error_list = zeros(4, m);
for j = 1:m
    delta_t = 2 ^ (-j);
    t = inteval(1):delta_t:inteval(2);
    exact_value = feval(exact_func, t, u0);
    for i = 1:4
        [t, u] = Runge_Kutta(func, inteval, u0, delta_t, i);
        error_list(i, j) = max(abs(u - exact_value));
    end
end
for i = 1 : 4
    semilogy(1:1:13, error_list(i, :), cell2mat(symbol(i)));
    hold on;
end
legend('1st-order', '2nd-order', '3rd-order', '4th-order', 'Location',...
    'Best');
title('The absolute error of Runge-Kutta Iteration');
grid on;
    