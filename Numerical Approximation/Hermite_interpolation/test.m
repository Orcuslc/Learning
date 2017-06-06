tic
x_values = [ 1, 1, 2, 2 ];
f_values = [1, 0.2, 1.1486984, 0.1148698 ];
x_series = linspace( 0, 8, 1e4 );
Hermite_eval( x_values, f_values, x_series );
toc