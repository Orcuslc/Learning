format long;
f = @(x)([x(1)^2+x(2)^2-4; x(1)^2-x(2)^2-1]);
F = @(x)([2*x(1), 2*x(2); 2*x(1), -2*x(2)]);
x0 = [1.6; 1.2];
max_it = 100;
tol = 1e-6;
[x, error, count] = Newton(f, F, x0, max_it, tol);
disp(x(1:count, 1:2));