%test of euler iteration
% P66, Example 2.2.2
func = @(t, u)(u - u .^ 2);
u0 = 1.5;
inteval = [0, 8];
delta_t = 1/8;
op = 'explicit';
op2 = 'implicit';
op3 = 'modified';
op4 = 'revised';
[t, u] = Euler_iter(func, inteval, u0, delta_t, op);
[t2, u2] = Euler_iter(func, inteval, u0, delta_t, op2);
[t3, u3] = Euler_iter(func, inteval, u0, delta_t, op3);
[t4, u4] = Euler_iter(func, inteval, u0, delta_t, op4);
plot(t, u, '*-');
hold on
plot(t2, u2, '.-');
hold on
plot(t3, u3, 'd-');
hold on
plot(t4, u4, 'o-');
hold on
exact_func = @(x, u0)(1 ./ ((1/u0 - 1) .* exp(-x) + 1));
exact_value = feval(exact_func, t, u0);
plot(t, exact_value, '-');

