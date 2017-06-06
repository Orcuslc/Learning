function [ coeff_vector ] = leastq_coeff( points, order )
%LEASTQ 输入给定点的N*2矩阵points, 以及拟合的阶数order, （其中order << N）
%输出拟合的系数向量，用coeff_vector表示

if ( sort( points( : , 1 ) , 'ascend' ) ~= points( : , 1 ) )
    error( ' Points are not in ascend order ' );
end

N = length( points );

%初始化法方程的系数矩阵
X = zeros( N, order + 1 );
X( : , 1 ) = 1;
X( : , 2 ) = points( : , 1 );
for i = 3 : order + 1
    X( : , i ) = X( : , i - 1 ) .* points( : , 1 );
end

%构造法方程，并求出解
Y = transpose( X );
coeff_vector = ( Y * X ) \ ( Y * points( : , 2 ) );


