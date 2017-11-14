function res = RK43D(f1, f2, f3, X0, h, t)
% RK4 method in 3d case;
% fi: component in each dimension
% X0 = (x0, y0, z0): initial values
% h: step size
% t = (t0, t1): time period
t0 = t(1)-h; t1 = t(2);
nstep = (t1-t0)/h;
res = zeros(nstep, 3);
x0 = X0(1); y0 = X0(2); z0 = X0(3);
for i = 1:nstep
    t0 = t0+h;
    res(i, 1) = x0; res(i, 2) = y0; res(i, 3) = z0;
    X1 = x0; Y1 = y0; Z1 = z0;
    X2 = x0+h/2*f1(t0, X1, Y1, Z1);
    Y2 = y0+h/2*f2(t0, X1, Y1, Z1);
    Z2 = z0+h/2*f3(t0, X1, Y1, Z1);
    X3 = x0+h/2*f1(t0+h/2, X2, Y2, Z2);
    Y3 = y0+h/2*f2(t0+h/2, X2, Y2, Z2);
    Z3 = z0+h/2*f3(t0+h/2, X2, Y2, Z2);
    X4 = x0+h*f1(t0+h/2, X3, Y3, Z3);
    Y4 = y0+h*f2(t0+h/2, X3, Y3, Z3);
    Z4 = z0+h*f3(t0+h/2, X3, Y3, Z3);
    x0 = x0+h/6*(f1(t0, X1, Y1, Z1)+2*f1(t0+h/2, X2, Y2, Z2)...
        +2*f1(t0+h/2, X3, Y3, Z3)+f1(t0+h, X4, Y4, Z4));
    y0 = y0+h/6*(f2(t0, X1, Y1, Z1)+2*f2(t0+h/2, X2, Y2, Z2)...
        +2*f2(t0+h/2, X3, Y3, Z3)+f2(t0+h, X4, Y4, Z4));
    z0 = z0+h/6*(f3(t0, X1, Y1, Z1)+2*f3(t0+h/2, X2, Y2, Z2)...
        +2*f3(t0+h/2, X3, Y3, Z3)+f3(t0+h, X4, Y4, Z4));
end
