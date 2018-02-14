k = 1; gamma = 1;

u = @(x, t) k*t+0.5*x.^2;
v = @(x, t) exp(-gamma^2*k*t)*sin(gamma*x);
w = @(x, t) exp(-gamma^2*k*t)*cos(gamma*x);
z1 = @(x, t) exp(k*t+x);
z2 = @(x, t) exp(k*t-x);

a = 10; T = 10;
x = 0:0.01:a;
t = 0:0.01:T;
[X, T] = meshgrid(x, t);

% uu = u(X, T);
% surf(uu);

% vv = v(X, T);
% surf(vv);

% ww = w(X, T);
% surf(ww);

% zz1 = z1(X, T);
% surf(zz1);

zz2 = z2(X, T);
surf(zz2);