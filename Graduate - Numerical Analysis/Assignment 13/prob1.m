f1 = @(x) 0.5*exp(-1/4*(x+1).^2);
f2 = @(x) 0.5^3.5*(x+1).^2.5;
f3 = @(x) 4./(1+16*x.^2);
f4 = @(x) pi./(2-cos(pi*x));
f5 = @(x) pi/2*exp(pi/2*(x+1)).*cos(2*pi*x);

N = 7;
res = zeros(N, 5);
for i = 1:N
    res(i, 1) = gauss_legendre(f1, i+1);
    res(i, 2) = gauss_legendre(f2, i+1);
    res(i, 3) = gauss_legendre(f3, i+1);
    res(i, 4) = gauss_legendre(f4, i+1);
    res(i, 5) = gauss_legendre(f5, i+1);
end
err = abs(res(2:N, :)-res(1:N-1, :))/res(1:N-1, :);
dlmwrite('prob1_res.m', res, 'delimiter', ' ', 'precision', '%2.10f');