function [ output ] = Bernstein_function( n )
% tic;
t_points = linspace( 0, 1, 1e2 );
f_series = cell( n );
for i = 1 : n
    f_series{ i } = @( t )( nchoosek( n, i ) .* ( t .^ i ) .* (( 1 - t ) .^ ( n - i )));
end
% for i = 1 : n
%     plot( t_points, f_series{ i }( t_points ) );
%     hold on;
% end
output = f_series;
% toc;