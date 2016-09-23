function [C] = mmloop(A, B, C)
% Using Loop update to calculate matrix multiplication;
% A, B, C: n*n Matrix;

[n, ~] = size(A);

for i = 1:n
    for j = 1:n
        for k = 1:n
            C(i, j) = C(i, j) + A(i, k)*B(k, j);
        end
    end
end
