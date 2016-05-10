function [ x ] = daubechies_recomposition( x, noise_matrix )
% DAUBECHIES_RECOMPOSITION 
% Recomposition of daubechies wavelet.

c1 = [(1+sqrt(3))/4, (3+sqrt(3))/4, (3-sqrt(3))/4, (1-sqrt(3))/4] / sqrt(2);
c2 = [c1(4), -c1(3), c1(2), -c1(1)];
[~, col] = size(noise_matrix);
for i = col:-1:1
    x = daubechies_recomposition_iter(x, noise_matrix(:, i), c1, c2);
end

end

