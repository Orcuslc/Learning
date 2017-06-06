function [ value ] = leastq_eval( args, eval_points_x )
%多项式求值函数，输入参数中args为多项式的系数向量，按照系数对应的次数从低到高排列
%eval_points_x为要求值点的横坐标，用一个列向量表示

%把eval_points表示成如
%[ 1, x1, x1^2, ..., x1^n ]
%[ 1, x2, x2^2, ..., x2^n ]
%...
%[ 1, xk, xk^2, ..., xk^n ]
%的形式

m = length( eval_points_x );
n = length( args );
M = zeros( m, n );
M( : , 1 ) = 1;
M( : , 2 ) = eval_points_x;


for i = 3 : n
    M( : , i ) = M( : , i - 1 ) .* eval_points_x;
end

value = M * args;


