function [ output ] = D2_spline_coefficient( given_points, function_values, S )
%D2_SPLINE_COEFFICIENT 输入的x_values为给定的小区间端点，f_values为函数在这些端点上的取值
% S为给定的特殊条件，在这里为两端的二阶导数值，输出此分段函数的二阶导数的系数M( j )
n = length( given_points );

%计算每个区间的长度，用向量h存储
h = given_points( 2 : n ) - given_points( 1 : n - 1 );

%计算三对角矩阵的系数，用向量a和b存储
mu = zeros( 1, n - 3 );
lambda = zeros( 1, n - 3 );
mu( 1 : n - 3 ) = h( 2 : n - 2 ) ./ ( h( 2 : n - 2 ) + h( 3 : n - 1 ) );
lambda( 1 : n - 3 ) = h( 2 : n - 2 ) ./ ( h( 1 : n - 3 ) + h( 2 : n - 2 ) );

%计算线性方程组的常数项，用向量d存储
d = zeros( 1, n - 2 );

d( 1 : n - 2 ) = 6 .* ( ( function_values( 3 : n ) - function_values( 2 : n - 1 ) ) ./ h( 2 : n - 1 ) - ( function_values( 2 : n - 1 ) - function_values( 1 : n - 2 ) ) ./ h( 1 : n - 2 ) ) ./ ( h( 2 : n - 1 ) + h( 1 : n - 2 ) );

%代入特殊条件

d( 1 ) = d( 1 ) - h( 1 ) / ( h(1) + h(2) ) * S( 1 );
d( n - 2 ) = d( n - 2 ) - h( n - 1 ) / ( h(n-1) + h(n - 2)) * S(2);


% 构造三对角矩阵
mid = zeros( 1, n -2 );
mid = mid + 2;
M = diag( mid ) + diag( lambda, 1 ) + diag( mu, -1 );

%解三弯矩方程，得到系数向量
temp_output = M \ d';
output = zeros( 1, n );
output( 2 : n-1 ) = temp_output;
output(1) = S(1);
output(n) = S(2);
end