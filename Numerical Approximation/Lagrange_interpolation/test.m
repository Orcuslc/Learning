%TEST of Lagrange_interpolation
given_points = linspace(0, pi, 10);
given_values = sin(given_points) + rand(1, length(given_points)) * 0.01;
eval_points = linspace( 0, pi, 1e2 );
values = lagrange_eval( given_points, given_values, eval_points );
plot( eval_points, values );
hold on;
plot( given_points, given_values, '*');
axis([0, pi, 0, 1]);