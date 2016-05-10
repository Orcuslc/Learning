function [y] = convolution(x, h)
% convolution of the two vectors x and h
% when the two vectors are row vectors
[row1, col1] = size(x);
[row2, col2] = size(h);

A = zeros(col1 + col2 - 1, col2);
for i = 1:col2
    A(i:i + col1 - 1, i) = transpose(x);
end
y = A * transpose(h);
% y = y / sum(h);

% In order to constrain the length of y;
y = y(2:length(y));

