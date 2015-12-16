function [ values ] = fourier_eval( coeff, eval_points_x )
%FOURIER_EVAL Fourier������ֵ������Fourier������n*2��ϵ������coeff���Լ���ֵ����ɵ�������eval_points_x,
%�����������Щ�㴦��ֵvalues

[ row, ~ ] = size( coeff );
n = length( eval_points_x );

values = zeros( n, 1 );
values = values + coeff( 1, 1 ) / 2;

for i = 2 : row
    values = values + coeff( i, 1 ) .* cos( ( i - 1 ) .* eval_points_x ) + coeff( i, 2 ) .* sin( ( i - 1 ) .* eval_points_x );
end

end

