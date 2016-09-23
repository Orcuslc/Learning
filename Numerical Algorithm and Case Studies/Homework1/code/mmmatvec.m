function [C] = mmmatvec(A, B, C)
% Using MatVec update to calculate matrix multiplication;
% A, B, C: n*n Matrix;

[n, ~] = size(A);

for j = 1:n
    C(:, j) = C(:, j) + A*B(:, j);
end