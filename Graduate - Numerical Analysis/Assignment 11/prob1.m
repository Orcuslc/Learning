f = @(x)sin(pi*x/2);
p = @(x)sqrt(7/2)*(120/pi^2)*(1-10/pi^2)*x.^3+...
    +(8/pi^3)*(sqrt(3/2)-9*sqrt(7/2)*(1-10/pi^2))*x;
t = @(x)4/3*x.^3-2/3*x;
ttrue = @(x) -0.552*x.^3+1.548*x;

x = -1:1e-2:1;
errp = abs(f(x)-p(x));
errt = abs(f(x)-t(x));
errtt = abs(f(x)-ttrue(x));
plot(x, errp, '.');
hold on;
plot(x, errt, '*');
hold on;
plot(x, errtt, 'd');
legend('Legendre', 'Chebyshev', 'Chebyshev True');
title('Error of Legendre and Chebyshev approximation');
grid on;