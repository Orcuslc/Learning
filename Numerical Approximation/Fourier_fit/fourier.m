function [ values ] = fourier( n, eval_points_x )
%FOURIER 对函数f = -1, 0 <= x < pi; f = 1, pi <= x < 2pi 进行傅里叶级数逼近，输入的n为逼近次数
%输入的eval_points_x为求值点，输出的values为逼近级数在这些点上的值

coeff = fourier_coeff( n );
values = fourier_eval( coeff, eval_points_x );


end

