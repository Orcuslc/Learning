function [   ] = Bezier_curve( control_points_x, control_points_y )
%BEZIER_CURVE Summary of this function goes here
%   control_points are changeable input arguments, which controls the
%   position and shape of the curve
n = length( control_points_x );
t_series = linspace(0, 1, 1e3);

x_series = 0;
y_series = 0;

for i = 1 : n 
    x_series = x_series + control_points_x( i ) .* Bernstein_function(n - 1, i - 1, t_series);
    y_series = y_series + control_points_y( i ) .* Bernstein_function(n - 1, i - 1, t_series);
end

plot( x_series, y_series );
hold on;
plot( control_points_x, control_points_y, 'd-' );
% hold on;


