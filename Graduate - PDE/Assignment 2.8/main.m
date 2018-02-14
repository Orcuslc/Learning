f = @(x) 1;
g = @(t) exp(-.1*t);

xend = 10;
nstep = 40;
dt = 0.05;
dx = 0.1;

u = backward(xend, nstep, f, g, @c, dx, dt);

x = 0:dx:xend;

for i = 1:10:(nstep+1)
    plot(x, u(:, i));
    hold on;
end

legend('t=0', 't=0.5', 't=1.0', 't=1.5', 't=2.0');