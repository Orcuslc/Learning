function [ x, noise_matrix ] = daubechies_decomposite( x )
% DAUBECHIES_DECOMPOSITE 
% Decomposite of Daubechies wavelet
% x is the initial COLUMN vector;
% B is the result matrix;

% A is the coefficient matrix;
n = length(x);
% c1 = daubechies_coeff([1, 0, -1, 0]);
c1 = [(1+sqrt(3))/4, (3+sqrt(3))/4, (3-sqrt(3))/4, (1-sqrt(3))/4] / sqrt(2);
c2 = [c1(4), -c1(3), c1(2), -c1(1)];
k = log2(n);
noise_matrix = zeros(n, k-1);

for i = 1:k - 1
    [x, noise_matrix] = daubechies_iter(i, x, noise_matrix, c1, c2);
end
end

