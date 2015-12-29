% given_points = [1, 2, 3, 4, 6];
% function_values = [ log(1), log(2), log(3), log(4), log(6)];
% eval_points = [ 5 ];
% bc = [1, 1/6];
% type = 'D1';
% cubic_spline_interpolation( eval_points, given_points, function_values, bc, type );

% given_points = [1.01, 2.01, 3.01, 4.01, 5.01, 5.99];
% function_values = [1, 2, 1,2, 1, 2];
% eval_points = linspace(1.02, 5.99, 1e2);
% cubic_spline_interpolation(eval_points, given_points, function_values);

given_points = [1.01, 2.01, 3.01, 4.01, 5.01, 5.99];
function_values = [1, 2, 1,2, 1, 1];
eval_points = linspace(1.01, 5.99, 1e2);
bc = [];
type = 'P';
cubic_spline_interpolation(eval_points, given_points, function_values, bc, type);
hold on
plot(given_points, function_values, '*');

