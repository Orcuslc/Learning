%TEST of Lagrange_interpolation
given_points = sort( rand( 1, 1e1 ) );
given_values = sort( rand( 1, 1e1 ) );
eval_points = linspace( 0, 1, 1e2 );
values = lagrange_eval( given_points, given_values, eval_points );
plot( eval_points, values );
hold on;
plot( given_points, given_values, 'd');
axis([0, 1, 0, 1]);