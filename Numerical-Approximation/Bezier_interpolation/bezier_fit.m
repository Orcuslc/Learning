function [ P, func_output ] = bezier_fit( points, order )
%BEZIER_APPROXIMATION Summary of this function goes here
%   Detailed explanation goes here
t = parametrize( points );
B = zeros( order, length( points ) );
func = Bernstein_function( order - 1 );
B( 1, 1 ) = 1;
B( order, 1 ) = 1;
for i = 1 : order
    for j = 2 : length( points )
        B( i, j ) = func{ j - 1 }( t( i ) );
    end
end
Y = transpose( B );
P = Y * B \ ( Y * points( : , 2 ) );
func_output = Bernstein_function( order - 1 );
end

