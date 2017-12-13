format long;
f1 = @(x) exp(x-x.^2);
f2 = @(x) x.*exp(x)./((1+x.^2).^2);
f3 = @(x) exp(x).*sin(x)./x;

n = [2, 4, 6, 8];
res = zeros(4, 3);
for i = 1:4
    res(i, 1) = gauss_laguerre(f1, n(i));
    res(i, 2) = gauss_laguerre(f2, n(i));
    res(i, 3) = gauss_laguerre(f3, n(i));
end

err = res;
err(:, 1) = abs(err(:, 1)-sqrt(pi/2));
err(:, 2) = abs(err(:, 2)-1/2);
err(:, 3) = abs(err(:, 3)-pi/2);

dlmwrite('res31.m', res, 'delimiter', ' ', 'precision', '%2.10f');
dlmwrite('res32.m', err, 'delimiter', ' ', 'precision', '%2.10f');