% homework 4
clear all;
result_matrix = zeros(7, 6);
for n = 1:7
    func = get_func(n);
    result_matrix(n, 1) = integral(func, 0, 1);
    for order = 1:5
        func = get_func(n);
        result_matrix(n, order + 1) = gauss_integral(func, order);
    end
end
nlist = 1:5;
figure(1);
for i = 1 : 7
    plot(nlist, result_matrix(i, 2:6) - result_matrix(i, 1));
    hold on
end
title('The error of Gauss-Legendre formula');
legend('x^1', 'x^2', 'x^3', 'x^4', 'x^5', 'x^6', 'x^7', 'Location', 'Best');