% prob4
x = 0:1e-3:2*pi;
% res = zeros(10, length(x));
m = 5;
error = zeros(m, 1);
for n = 1:m
    xx = linspace(0, 2*pi, 2*n);
    xx(2:2:end) = xx(1:2:end);
    yy = cos(xx);
    yy(2:2:end) = -sin(xx(2:2:end));
    val = Hermite_poly(xx, yy, x);
    error(n, 1) = max(abs(val-cos(x)));
    plot(x, abs(val-cos(x)));
    hold on;
end
disp(error);
legend('n=1', 'n=2', 'n=3', 'n=4', 'n=5', 'Location', 'Best');
title('Error with order'); xlabel('x'); ylabel('Error');
