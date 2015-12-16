function [ values ] = fourier_eval( coeff, eval_points_x )
%FOURIER_EVAL Fourier级数求值，输入Fourier级数的n*2的系数矩阵coeff，以及求值点组成的列向量eval_points_x,
%输出级数在这些点处的值values

[ row, ~ ] = size( coeff );
n = length( eval_points_x );

values = zeros( n, 1 );
values = values + coeff( 1, 1 ) / 2;

for i = 2 : row
    values = values + coeff( i, 1 ) .* cos( ( i - 1 ) .* eval_points_x ) + coeff( i, 2 ) .* sin( ( i - 1 ) .* eval_points_x );
end

end

