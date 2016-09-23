function [C] = mmouterdot(A, B, C)
% Using OuterDot update to calculate matrix multiplication;
% A, B, C: n*n Matrix;

[n, ~] = size(A);

for j = 1:n
    C = C + A(:, j)*B(j, :);
end