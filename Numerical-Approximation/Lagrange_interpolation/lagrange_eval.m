function [ values ] = lagrange_eval( given_points, given_values, eval_points )
%given_points, given_values分别为给定的x坐标点，以及在这些点上的函数值；
%eval_points为一个向量，表示所要求值的点

n = length( given_points );
m = length( eval_points );
values = zeros( 1, m );
disp( given_points );

for i = 1 : n
        multiple_temp = zeros( 1, m ) + 1;
        for j = 1 : n
            if j ~= i
                multiple_temp = multiple_temp .* ( eval_points - given_points( j )) ./ ( given_points( i ) - given_points( j ));
            end
        end
        disp( multiple_temp);
        values = values + multiple_temp * given_values( i );
end
