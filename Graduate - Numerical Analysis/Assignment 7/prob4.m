% prob4
x = 0:1e-3:2*pi;
% res = zeros(10, length(x));
m = 10;
error = zeros(m, 1);
for n = 1:m
    xx = linspace(0, 2*pi, n);
    val = newton_poly(xx, cos(xx), x);
    error(n, 1) = max(abs(val-cos(x)));
    plot(x, abs(val-cos(x)));
    hold on;
end
disp(error);
legend('n=1', 'n=2', 'n=3', 'n=4', 'n=5',...
    'n=6', 'n=7', 'n=8', 'n=9', 'n=10', 'Location', 'Best');
title('Error with order'); xlabel('x'); ylabel('Error');
