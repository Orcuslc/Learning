function [ y ] = daubechies_coeff( x )
% DAUBECHIES_COEFF 
% solve the coefficients of daubechies matrix
% x is the initial vector
% return a vector;

y = fsolve(@daubechies_r, x);

end

function [ y ] = daubechies_r( x )

y = zeros(1, 4);
y(1) = x * transpose(x) - 1;
y(2) = x(1) * x(4) + x(2) * x(3);
y(3) = x(4) - x(3) + x(2) - x(1);
y(4) = -x(3) + 2*x(2) - 3*x(1);
end