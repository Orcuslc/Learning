function [ output ] = D1_spline_coefficient( given_points, function_values, S )
%D1_SPLINE_COEFFICIENT 输入的given_points为给定的小区间端点，f_values为函数在这些端点上的取值
% S为给定的特殊条件，在这里为两端的一阶导数值，输出此分段函数的二阶导数的系数M( j )
n = length( given_points );

%计算每个区间的长度，用向量h存储
h = given_points( 2 : n ) - given_points( 1 : n - 1 );

%计算三对角矩阵的系数，用向量a和b存储
mu = zeros( 1, n - 1 );
lambda = zeros( 1, n - 1 );
mu( 1 : n - 2 ) = h( 1 : n - 2 ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );
lambda( 2 : n - 1 ) = h( 2 : n - 1 ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );

%计算线性方程组的常数项，用向量d存储
d = zeros( n, 1 );
d( 2 : n - 1 ) = 6 * (( function_values( 3 : n ) - function_values( 2 : n - 1 ) ) ./ h( 2 : n - 1 ) - ( function_values( 2 : n - 1 ) - function_values( 1 : n - 2 ) ) ./ h( 1 : n - 2 )) ./ ( h( 2 : n - 1 ) + h( 1 : n - 2 ) );

%代入特殊条件
mu( n - 1 ) = 1;
lambda( 1 ) = 1;
d( 1 ) = 6 / h( 1 ) * ( ( function_values( 2 ) - function_values( 1 ) ) / h( 1 ) - S( 1 ) );
d( n ) = 6 / h( n - 1 ) * ( S( 2 ) - ( function_values( n ) - function_values( n - 1 ) ) / h( n - 1 ) );

% 构造三对角矩阵
mid = zeros( 1, n );
mid = mid + 2;
M = diag( mid ) + diag( lambda, 1 ) + diag( mu, -1 );

% disp(M);
% disp(d);
%解三弯矩方程，得到系数向量
output = M \ d;
% disp(output);

end

