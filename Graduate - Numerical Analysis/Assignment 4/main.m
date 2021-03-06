f1 = @(x)(exp(x)-3*x^2);
df1 = @(x)(exp(x)-6*x);
f2 = @(x)(x-1-0.3*cos(x));
df2 = @(x)(1+0.3*sin(x));
tol = 1e-6;
format long;

% f1: Prob 2(a); 
figure(1);
% FOR THE NEGATIVE ROOT
% bisection
a = -1; b = 0;
[root, index, iteration, error, count] = bisection(f1, a, b, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
hold on;
% Newton
x0 = -0.5;
[root, index, iteration, error, count] = newton(f1, df1, x0, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
hold on;
% Secant
x0 = -1; x1 = 0;
[root, index, iteration, error, count] = secant(f1, x0, x1, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
title('Error estimation for e^x-3x^2, the negative root');
legend('Bisection', 'Newton', 'Secant');
% for the smaller positive root
% bisection
figure(2);
a = 0; b = 1;
[root, index, iteration, error, count] = bisection(f1, a, b, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
hold on;
% Newton
x0 = 0.5;
[root, index, iteration, error, count] = newton(f1, df1, x0, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
hold on;
% Secant
x0 = 0; x1 = 1;
[root, index, iteration, error, count] = secant(f1, x0, x1, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
title('Error estimation for e^x-3x^2, the smaller positive root');
legend('Bisection', 'Newton', 'Secant');
% for the larger positive root
% bisection
figure(3);
a = 1; b = 4;
[root, index, iteration, error, count] = bisection(f1, a, b, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
hold on;
% Newton
x0 = 3.5;
[root, index, iteration, error, count] = newton(f1, df1, x0, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
hold on;
% Secant
x0 = 3; x1 = 4;
[root, index, iteration, error, count] = secant(f1, x0, x1, tol);
disp([index(1:count), iteration(1:count), error(1:count)]);
semilogy(index(1:count), error(1:count));
title('Error estimation for e^x-3x^2, the larger positive root');
legend('Bisection', 'Newton', 'Secant');

% 
% % f2: Prob 2(d);
% figure(2);
% % bisection
% a = 0; b = pi/2;
% [root, index, iteration, error, count] = bisection(f2, a, b, tol);
% disp([index(1:count), iteration(1:count), error(1:count)]);
% semilogy(index(1:count), error(1:count));
% hold on;
% % Newton
% x0 = 0.5;
% [root, index, iteration, error, count] = newton(f2, df2, x0, tol);
% disp([index(1:count), iteration(1:count), error(1:count)]);
% semilogy(index(1:count), error(1:count));
% hold on;
% % Secant
% x0 = 0; x1 = 1;
% [root, index, iteration, error, count] = secant(f2, x0, x1, tol);
% disp([index(1:count), iteration(1:count), error(1:count)]);
% semilogy(index(1:count), error(1:count));
% 
% title('Error estimation for x-1-0.3cos(x)');
% legend('Bisection', 'Newton', 'Secant');