function [ X, Y ] = bezier_fit( points, order )
%BEZIER_APPROXIMATION Summary of this function goes here
%   Detailed explanation goes here
t = parametrize( points );
B = zeros( length(points), order );
% func = Bernstein_function( order - 1 );
% B( 1, 1 ) = 1;
% B( order, 1 ) = 1;
for i = 1 : length(points)
    for j = 1 : order
%         B( i, j ) = func{ j - 1 }( t( i ) );
        B(i, j) = Bernstein_function(order - 1, j - 1, t(i));
    end
end
C = transpose(B);
X = (C*B) \ (C * transpose(points(1, :)));
Y = (C*B) \ (C * transpose(points(2, :)));
end

