f1 = @(x) exp(x);
alpha1 = 1/pi;
b1 = 1;

f2 = @(x) pi./(2.*sin(x));
alpha2 = 1-pi/2;
b2 = 1;

n = 10;
res = zeros(n, 2);
for i = 2:n
%     disp(product_trapezoidal(f1, b1, i, alpha1))
    res(i, 1) = product_trapezoidal(f1, b1, i, alpha1);
    res(i, 2) = product_trapezoidal(f2, b2, i, alpha2);
end

dlmwrite('res4.m', res, 'delimiter', ' ', 'precision', '%2.10f');