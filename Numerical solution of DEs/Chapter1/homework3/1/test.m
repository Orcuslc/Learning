% f = @(x, n)(x .^ n);
% g = @(n)(f(x, n));
inteval = [0, 1];
result_matrix = zeros(7, 6);
for n = 1:7
    func = get_func(n);
    result_matrix(n, 1) = integral(func, 0, 1);
    for order = 0:4
        func = get_func(n);
        result_matrix(n, order + 2) = newton_cotes(func, inteval, order);
    end
end
disp(result_matrix)