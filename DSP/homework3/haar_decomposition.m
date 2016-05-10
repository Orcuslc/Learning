function [A, B] = haar_decomposition(x, y, J)
% Use Convolution to achieve haar decomposition;
% x : The x-axis of signal;
% y : The y-axis of signal;
% X, Y are discrete points with a sampling interval
% of 1/2^n * length(time);

n = length(x);
% J is the highest level of y = f(x);
% Decomposite f into sum of f0, w0, w1, ..., w_(J-1)
% J = log2(n);
A = zeros(J + 1, n);
B = zeros(J + 1, n);
A(1, :) = y;

% h and l are respectively discrete filters.
l = [0.5, 0.5];
h = [-0.5, 0.5];

% The i_th row of B is the coefficient of w_(J-i)
% and the i_th row of A is the coefficient of f_(J-i+1)
for i = 1:J
% A(i+1, :) is calculated by the convolution of
% A(i, :) and h, while B(i, :) by A(i, :) and l.
    tA = convolution(A(i, 1:n), l);
    tA = down_sampling(tA);
    n = n/2;
    A(i+1, 1:n) = tA;
    tB = convolution(A(i, 1:2*n), h);
    tB = down_sampling(tB);
    B(i, 1:n) = tB;
end
B(J+1, :) = A(J+1, :);
