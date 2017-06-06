function [ output ] = spline_eval( coeff_matrix, given_points, eval_points )

pos = zeros( 1, length( eval_points ) );

%�ҵ�x_seriesÿ��Ԫ������Ӧ��С����


for i = 1 : length( eval_points )
    pos( i ) = find( given_points >= eval_points( i ) , 1, 'first' ) - 1;
    if( pos(i)) == 0
        pos(i) = 1;
    end
end

%����x_seriesÿ��Ԫ���ϵĺ���ֵ

output = coeff_matrix( 1, pos ) + ( eval_points - given_points( pos ) ) .* coeff_matrix( 2, pos ) + coeff_matrix( 3, pos ) .* ( eval_points - given_points( pos ) ) .^ 2  + coeff_matrix( 4, pos ) .* ( eval_points - given_points( pos ) ) .^ 3;
plot( eval_points, output );
