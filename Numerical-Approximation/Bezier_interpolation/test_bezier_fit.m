%test of bezier_fit
n = 12;
t_series = linspace( 0, 2*pi, n );
x = cos( t_series );
y = sin( t_series );
points = [x; y];
order = 4;
[X, Y] = bezier_fit(points, order);
% plot_x = linspace(-10, 10, 1e3);
% plot_y = 
plot(x, y, '*')
hold on;
disp(X);
disp(Y);
Bezier_curve( transpose(X), transpose(Y) );