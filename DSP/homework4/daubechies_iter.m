function [ x, noise_matrix ] = daubechies_iter( n, x, noise_matrix, c1, c2 )
% DAUBECHIES_ITER 
% The iteration of daubechies decomposition
% n is the index of the iteration
% x is the smooth vector;
% noise_matrix is the noise matrix;
% c1, c2 are used to init the iterational matrix;

k = length(x);
% [row, ~] = size(noise_matrix);
A = daubechies_matrix(k, c1, c2);
y = A * x;
x = y(1:2:k-1);
noise_matrix(1:k/2, n) = y(2:2:k);
end

