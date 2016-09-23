function [C] = mmdaxpy(A, B, C)
% Using Daxpy update to calculate matrix multiplication;
% A, B, C: n*n Matrix;

[n, ~] = size(A);

for i = 1:n
    for j = 1:n
        C(:, i) = C(:, i) + A(:, j)*B(j, i);
    end
end