r = @(omega)(5-4.*cos(omega));
phi  = @(omega)(mod(2*(pi - atan(sin(omega) ./ (2-cos(omega))) - omega), 2*pi));

xx = 0:1e-6:2*pi;
ry = r(xx);
phiy = phi(xx);

plot(xx, ry);
hold on;
plot(xx, phiy);

legend('amplitude', 'argument', 'Location', 'Best');
title('The amplitude and argument with omega');
grid on;