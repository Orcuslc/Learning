function u = explicit_finite_diff(x0, x1, dx, dt, tend, f, bd0, bd1, k)

x = x0:dx:x1;
t = 0:dt:tend;
nx = length(x);
nt = length(t);
s = dt/(dx^2)*k;

u = zeros(nx, nt);
u(:, 1) = f(x);
u(1, :) = bd0(t);
u(nx, :) = bd1(t);

for n = 2:nt
    u(2:nx-1, n) = (1-2*s)*u(2:nx-1, n-1) + s*(u(3:nx, n-1)+u(1:nx-2, n-1));
end