function [b] = row_back_substitute(U, b)
% ROW_BACK_SUBSTITUTE
% Using Row-oriented back substitute to solve
% upper triangle system.
% U: an upper triangle matrix
% b: a vector;

[n, ~] = size(U);

b(n) = b(n)/U(n, n);
for i = (n-1):-1:1
    b(i) = (b(i)-U(i, i+1:n)*b(i+1:n))/U(i, i);
end

end

