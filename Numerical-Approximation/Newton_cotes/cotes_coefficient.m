function [ coeff ] = cotes_coefficient( order )
%Calculate the cotes coefficient with the order given
%Use the equation given at Page179, exercise3
n = order
matrix = zeros(n, n);
for i = 1 : n
    matrix( i , : ) = (1:n) .^ i;
end
c = (n .^ (1:n)) ./ (2:n+1);
c = transpose(c);
coeff = matrix \ c;
coeff = [coeff(n); coeff];
end

