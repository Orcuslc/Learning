function [C] = mmdot(A, B, C)
% Using Dot update to calculate matrix multiplication;
% A, B, C: n*n Matrix;

[n, ~] = size(A);

for i = 1:n
    for j = 1:n
        C(i, j) = C(i, j) + A(i, :)*B(:, j);
    end
end