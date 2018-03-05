u = @(x, t) 5*sin(2*x).*exp(-4*t)-2*sin(3*x).*exp(-9*t)+3*sin(5*x).*exp(-25*t);

x = 0:pi/100:pi;
for i = [0, .5, 1, 2, 5]
    plot(x, u(x, i)); hold on;
end

