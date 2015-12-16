function [ output ] = cubic_spline_interpolation( eval_points, given_points, function_values, boundary_condition, spline_type )
%三次样条求值
%输入：eval_points为求值点，given_points,
%function_values分别为插值点的x，y坐标，boundary_condition为边界条件，spline_type为样条类型
%输出： 样条函数在求值点处的值
if nargin < 3
    error ( 'args input error' );
elseif nargin == 3
        boundary_condition = [ 0, 0 ];
        spline_type = 'D2';
elseif nargin == 4
        spline_type = 'D3';
end

coeff = spline_coefficient( given_points, function_values, boundary_condition, spline_type );
output = spline_eval( coeff, given_points, eval_points );


