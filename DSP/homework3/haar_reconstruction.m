function [a] = haar_reconstruction(A, B)
% Reconstruction of Haar Wavelet
% B : The result of haar_decomposition, with some kind of handling;

[row, col] = size(B);

h = [1, -1];
l = [1, 1];
a = A(row, 1:max(1, col/(2^(row-1))));
length(a)
for i = row-1:-1:1
    a1 = up_sampling(a);
    a1 = convolution(a1, l);
    b = up_sampling(B(i, 1:col/(2^(i))));
    b = convolution(b, h);
    length(b)
    a = a1 + b;
end

