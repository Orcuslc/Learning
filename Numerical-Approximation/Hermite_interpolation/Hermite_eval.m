function [  ] = Hermite_eval( given_points, function_values, eval_points )
%HERMITE_EVAL 用Hermite插值多项式，求出函数在一些点的近似值，并画出图像
%   x_values和f_values是输入的有关插值条件，x_series为输入的求值点

%调用Hermite_coefficient函数求出Newton插值多项式的各项系数，从低到高排列
args = Hermite_coefficient( given_points, function_values );

%调用polynimail_eval函数求出上述多项式在X各项处的值，其中X为向量或者数据点
f_series = polynomail_eval(args, eval_points, given_points);

%画出图像
plot( eval_points, f_series );
hold on;
plot( given_points, function_values, 'd');
end


