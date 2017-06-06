%test
x_series = linspace( 0, pi, 1e2 );
x_values = linspace(0, pi, 10);
f_values = sin( x_values );
Newton_eval( x_values, f_values, x_series );
axis([0, pi, -1, 1]);
