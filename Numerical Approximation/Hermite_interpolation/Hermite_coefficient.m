function [ output ] = Hermite_coefficient( given_points, function_values )
%���Hermite��ֵ����ʽ��ϵ��������given_pointsΪ����Ĳ�ֵ�ڵ㣬function_valuesΪ����ĺ���ֵ���ߵ���ֵ

% n Ϊ�����given_points�����ĳ���
n = length( given_points );
H = zeros( n, n );

% �������f_series�е�������Ϊ������f��k�׵�����ת��Ϊ���̱��еĵ�һ��
for i = 1 : n
    H( i, 1 ) = function_values( find( given_points == given_points( i ), 1, 'first' ) );
end;

for i = 2 : n
    for j = 1 : n - i + 1
        % pos1 Ϊx_values( j )��һ�γ��ֵ�λ�ã�pos2Ϊx_values( i + j - 1)
        %��һ�γ��ֵ�λ�ã� ���pos1 = pos2�� �����ζ������ѭ����x_values( j )
        % = x_values( i + j - 1)��Ҳ��ζ�Ų��̱�����λ��Ӧ�õ��������棻
        %������f_values�е�λ�ü�Ϊpos + j - 1;
        pos1 = find( given_points == given_points( j ), 1, 'first' );
        pos2 = find( given_points == given_points( i + j - 1), 1, 'first' );
        if pos1 == pos2
            H( j, i ) = function_values( pos1 + i - 1) / factorial( i - 1);
        else
            H( j , i) = ( H( j + 1, i - 1) - H( j, i - 1 ) ) / ( given_points( i + j - 1) - given_points( j ));
        end
    end
end
output = H( 1, : );
end



