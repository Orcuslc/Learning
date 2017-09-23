format long;
f = @(x)([x(1)^2+x(1)*x(2)^3-9; 3*x(1)^2*x(2)-x(2)^3-4]);
F = @(x)([2*x(1)+x(2)^3, 3*x(2)^2; 6*x(1)*x(2), 3*x(1)^2-3*x(2)^2]);
max_iter = 100;
tol = 1e-6;

%%%%%%%%%% Case 1 %%%%%%%%
% figure(1);
% x0 = [1.2; 2.5];
% [x, error, count] = Newton(f, F, x0, max_iter, tol);
% disp(x(1:count, 1:2));
% disp(count);
% semilogy(1:count, error(1:count));
% legend('Convergence Rate');
% title('Convergence rate for init = (1.2, 2.5)');
% xlabel('Iteration Count');
% ylabel('Error');
% grid on;

%%%%%%%%%% Case 2 %%%%%%%%
% figure(2);
% x0 = [-2; 2.5];
% [x, error, count] = Newton(f, F, x0, max_iter, tol);
% disp(x(1:count, 1:2));
% disp(count);
% semilogy(1:count, error(1:count));
% legend('Convergence Rate');
% title('Convergence rate for init = (-2, 2.5)');
% xlabel('Iteration Count');
% ylabel('Error');
% grid on;

%%%%%%%%% Case 3 %%%%%%%%%
% figure(3);
% x0 = [-1.2; -2.5];
% [x, error, count] = Newton(f, F, x0, max_iter, tol);
% disp(x(1:count, 1:2));
% disp(count);
% semilogy(1:count, error(1:count));
% legend('Convergence Rate');
% title('Convergence rate for init = (-1.2, -2.5)');
% xlabel('Iteration Count');
% ylabel('Error');
% grid on;

%%%%%%%% Case 4 %%%%%%%%%
figure(4);
x0 = [2; -2.5];
[x, error, count] = Newton(f, F, x0, max_iter, tol);
disp(x(1:count, 1:2));
disp(count);
semilogy(1:count, error(1:count));
legend('Convergence Rate');
title('Convergence rate for init = (2, -2.5)');
xlabel('Iteration Count');
ylabel('Error');
grid on;