function [ values ] = lagrange_eval( given_points, given_values, eval_points )
%given_points, given_values�ֱ�Ϊ������x����㣬�Լ�����Щ���ϵĺ���ֵ��
%eval_pointsΪһ����������ʾ��Ҫ��ֵ�ĵ�

n = length( given_points );
m = length( eval_points );
values = zeros( 1, m );
disp( given_points );

for i = 1 : n
        multiple_temp = zeros( 1, m ) + 1;
        for j = 1 : n
            if j ~= i
                multiple_temp = multiple_temp .* ( eval_points - given_points( j )) ./ ( given_points( i ) - given_points( j ));
            end
        end
        disp( multiple_temp);
        values = values + multiple_temp * given_values( i );
end
