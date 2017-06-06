x = [ 0, pi, pi, 2*pi ];
y = [ -1, -1, 1, 1 ];
plot( x, y );
axis( [-1, 2*pi + 1, -2, 2] );
hold on;

eval_points_x = linspace( -0.25, 2 * pi + 0.25, 1e3 );
eval_points_x = transpose( eval_points_x );

for n = 1 : 100
    values = fourier( n, eval_points_x );
    plot( eval_points_x, values );
    hold on;
end
