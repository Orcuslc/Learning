function [ values_y ] = leastq( points, order, eval_points_x )
%LEASTQ 输入给定点的N*2矩阵points, 以及拟合的阶数order, （其中order <<
%N）,和要求值点的横坐标eval_points_x
%   输出拟合的多项式在这些点上的值values_y

coeff_vector = leastq_coeff( points, order );
values_y = leastq_eval( coeff_vector, eval_points_x );

end

