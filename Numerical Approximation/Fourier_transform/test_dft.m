%test of dft
t = linspace(0, 4*pi, 1e3);
fx = sin(t) + 1/5 * sin(5*t);
plot(t, fx, '.')
hold on
fy = dft_func(fx);
n = 3;
filter_y = [fy(1:n) zeros(1, 1e3-2*n), fy(1e3-n+1 : 1e3)];
x = ifft(filter_y);
plot(t, x);
title('Filter of sin(x)+sin(5x) using DFT')
legend('sin(5x)+sin(x)','sin(x)');