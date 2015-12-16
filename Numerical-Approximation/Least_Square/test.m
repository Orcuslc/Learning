N = 200;
order = 3;

x = sort( rand( N, 1 ) * 2 * pi );
y = sin( x ) + rand( N, 1 ) * 1;
eval_points_x = linspace( 0, 2 * pi, 1000 );
eval_points_x = transpose( eval_points_x );
% disp(eval_points_x);

points = [ x, y ];
values = leastq( points, order, eval_points_x );
plot( x, y, '.' );
hold on
% disp(length(values));
% disp(length(eval_points_x))
plot( eval_points_x, values );