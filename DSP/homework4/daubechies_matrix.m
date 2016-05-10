function [ A ] = daubechies_matrix( n, c1, c2 )
% DAUBECHIES_MATRIX 
% Get the matrix of daubechies iteration

A = zeros(n, n);

for i = 1: 2 : n-3
    A(i, i:i+3) = c1;
    A(i+1, i:i+3) = c2;
end

A(n-1, n-1:n) = c1(1:2);
A(n, n-1:n) = c2(1:2);
A(n-1, 1:2) = c1(3:4);
A(n, 1:2) = c2(3:4);

end

