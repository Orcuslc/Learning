%test.m
n =20;
t_series = linspace( 0, 2*pi, n );
x_points = cos( t_series );

y_points = sin( t_series );
% x_points = [ 0, 1, 1, 0];
% y_points = [ 0, 0, 1, 1];
Bezier_curve( x_points, y_points );