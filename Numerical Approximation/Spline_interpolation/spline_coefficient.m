function [ output ] = spline_coefficient( given_points, function_values, boundary_condition, type )
%�����������������ϵ������
%�����x_values��f_values�ֱ��ǲ�ֵ�ڵ������Щ�ڵ��ϵĺ���ֵ��
%b_cΪ�߽�������funcΪ'D1','D2','D3'�������ֵ����ʽ��ϵ������4 * len(x_values)

n = length( given_points );
%init the output matrix
output = zeros( 4, n  -  1);
output( 1,: ) = function_values( 1 : n - 1 );

%hΪ��ֵ�ڵ�Ĳ�������
h = given_points( 2 : n ) - given_points( 1 : n - 1 );

switch upper( type )
    case 'D1'
        M = D1_spline_coefficient( given_points, function_values, boundary_condition );   
        M = M';
        output( 3, : ) = M( 1 : n - 1 );
    case 'D2'
        M = D2_spline_coefficient( given_points, function_values, boundary_condition );   
        output( 3, : ) = M( 1 : n - 1 );
    case 'P'
        M = D3_spline_coefficient( given_points, function_values );   
        output( 3, : ) = M( 1 : n - 1 );
    otherwise
        error ( 'Unvalid Function' );
end
output( 2, : ) = ( function_values( 2 : n ) - function_values( 1 : n - 1 ) ) ./ h - ( 1/6 .* M( 2 : n ) + 1/3 .* M( 1 : n - 1 ) ) .* h;
output( 3, : ) = output( 3, : ) / 2;
output( 4, : ) = (M( 2 : n ) - M( 1 : n - 1 ) ) ./ h / 6;
end

