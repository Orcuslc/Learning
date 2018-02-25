k = 1;
dx = .25; dt = (dx^2)/2;
bd0 = @(t) 0; bd1 = @(t) 0;
f = @(x) sin(pi*x/10);
x0 = 0; x1 = 10; tend = 1000;

u = explicit_finite_diff(x0, x1, dx, dt, tend, f, bd0, bd1, k);
ut = @(x, t) sin(pi*x/10)*exp(-(pi/10)^2*t);

plot(x0:dx:x1, u(:, end), '-'); hold on;
plot(x0:dx:x1, ut(x0:dx:x1, tend), '.-');
maxErr = max(abs(u(:, end)-ut(x0:dx:x1, tend)'));

legend('Numerical', 'True');
title('t = '+string(tend)+', max error = '+string(maxErr));
% title('dt = '+string(dt));

