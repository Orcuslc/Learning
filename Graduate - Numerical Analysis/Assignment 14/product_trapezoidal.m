function res = product_trapezoidal(f, b, n, alpha)
% Product trapezoidal rule;
% Compute integral of `f` on `[0, b]` with order `n`;

phi1 = @(k) integral(@(u) u./(k-1+u).^alpha, 0, 1);
phi2 = @(k) integral(@(u) (1-u)./(k-1+u).^alpha, 0, 1);

h = b/n;
x = 0:h:b;
w = zeros(n+1, 1); w(1) = phi2(1); w(n+1) = phi1(n);
for i = 2:n
    w(i) = phi1(i-1)+phi2(i);
end
res = f(x)*w/(h^(alpha-1));
