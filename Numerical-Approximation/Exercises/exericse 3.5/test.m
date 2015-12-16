for n = 3:100
    sym x;
    disp('n');
    disp(n);
    x_values = linspace( 0.1, 0.99, n );
    f_values = sin(x_values) ./ x_values;
    f_values(1) = 1;
    x_series = linspace( 0.1, 0.99, 2*n);
    y = diff('sin(x)/x');
    pf_values = subs(y, x_values);
    
%     values = cubic_spline_interpolation( x_series, x_values, f_values );
values = hermite( x_values, f_values, pf_values, x_series);
    true_val = sin(x_series) ./ x_series;
    true_val(1) = 1;
    disp( max( abs( values - true_val)));
    
end