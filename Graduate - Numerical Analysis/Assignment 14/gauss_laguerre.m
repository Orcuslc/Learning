function res = gauss_laguerre(f, n)
% Gauss-Laguerre Quadrature
% f: func
% n: num of points

%%%% Reference: MATLAB documentation %%%%
syms t;
w(t) = exp(-t);
F = laguerreL(n, t);
x = vpasolve(F);

y = sym('y', [n, 1]);
sys = sym(zeros(n));
for k = 0:n-1
    sys(k+1) = sum(y.*(x.^k)) == int(t^k*w(t), t, 0, inf);
end
a = vpasolve(sys, y);
a = structfun(@double, a);
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
res = sum(a.*f(x));