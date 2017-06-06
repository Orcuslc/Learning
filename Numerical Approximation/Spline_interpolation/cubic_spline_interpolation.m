function [ output ] = cubic_spline_interpolation( eval_points, given_points, function_values, boundary_condition, spline_type )
%����������ֵ
%���룺eval_pointsΪ��ֵ�㣬given_points,
%function_values�ֱ�Ϊ��ֵ���x��y���꣬boundary_conditionΪ�߽�������spline_typeΪ��������
%����� ������������ֵ�㴦��ֵ
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


