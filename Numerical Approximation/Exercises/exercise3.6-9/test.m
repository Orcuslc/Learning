%exercise 3.6


% x_values = linspace(0, 1, 5);
% disp(x_values);
% f_values = sin( x_values ) ./ x_values;
% f_values(1) = 1;
% bc = [0, cos(1) - sin(1)];
% func = 'd1';
% x = spline_coefficient(x_values, f_values, bc, func);
% disp(x)


% x_values = linspace(-1, 1, 5);
% disp(x_values);
% f_values = abs(x_values);
% bc = [0, 0];
% func = 'd2';
% x = spline_coefficient(x_values, f_values, bc, func);
% disp(x);

% x_values = linspace(-1, 1, 6);
% disp(x_values);
% f_values = abs(x_values);
% func = 'd3';
% bc = 'null';
% x = spline_coefficient( x_values, f_values, bc, func);
% disp(x);

x_values = [532.58, 632.54, 737.42, 852.13, 983.22, 1133.98, 1310.97];
f_values = [12666.63, 11259.22, 9851.82, 8444.42, 7037.01, 5629.61, 4222.21];
bc = [0, 0];
func = 'd2';
x = spline_coefficient(f_values, x_values, bc, func);
disp(x);
y = cubic_spline_interpolation(1065.16, x_values, f_values, bc, func);
disp(y);