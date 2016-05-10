function [ t ] = daubechies_recomposition_iter( x, y, c1, c2 )
% DAUBECHIES_RECOMPOSITION_ITER 

n = length(x);
nx = zeros(2*n, 1);
nx(1:2:2*n-1) = x;
nx(2:2:2*n) = y(1:n);
A = daubechies_matrix(2*n, c1, c2);
A = transpose(A);

t = A * nx;
end

