function [ point, weight ] = gauss_coefficient_legendre( order )
% Calculate the coefficients of gauss integral formula with legendre
% polynomial.

b = 0.5 ./ sqrt(1 - (2 * (1:order)) .^ (-2));
[v, lambda] = eig(diag(b, 1) + diag(b, -1));
[point, i] = sort(diag(lambda));
weight = 2 * v(1, i) .^ 2;

end

