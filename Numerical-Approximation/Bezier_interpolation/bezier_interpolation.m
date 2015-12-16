function [  ] = bezier_interpolation( points )
%给定points,找出控制点Pi
t = parametrize( points );
n = length( points );
B = zeros( n, n );
func = Bernstein_function( n - 1 );
B( 1, 1 ) = 1;
B( 1, n ) = 1;
for i = 1 : n
    for j = 2 : n
        B( i, j ) = func{ j - 1 }( t( i ) );
    end
end
P1, P2 = B \ [ points( 1, : )', points( 2, : )' ];
Bezier_curve( P1', P2' );
end

