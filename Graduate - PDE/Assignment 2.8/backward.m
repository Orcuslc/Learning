function u = backward(xend, nstep, f, g, c, dx, dt)

x = 0:dx:xend; t = (0:1:nstep)*dt;
J = length(x);

u = zeros(J, nstep+1);
u(:, 1) = f(x);
u(1, :) = g(t);

for n = 1:nstep
    j = 2:J;
    u(j, n+1) = u(j, n) - dt/dx*(c(x(j))'.*u(j, n)-c(x(j-1))'.*u(j-1, n));
end
