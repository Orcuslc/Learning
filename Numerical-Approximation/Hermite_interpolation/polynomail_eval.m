function [value] = polynomail_eval( args, eval_points, given_points )
%多项式求值函数，输入参数中args为多项式的系数，按照次数从高到低排列；
%eval_points为要求值的向量；
%多项式形如(x-x1)(x-x2)(x-x3),其中given_points为给定的点
value = args( length( args ) );
for i = length( args ) - 1:-1:1
    value = value .* ( eval_points - given_points( i ) ) + args( i );
end;

