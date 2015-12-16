function [ output ] = D2_spline_coefficient( given_points, function_values, S )
%D2_SPLINE_COEFFICIENT �����x_valuesΪ������С����˵㣬f_valuesΪ��������Щ�˵��ϵ�ȡֵ
% SΪ����������������������Ϊ���˵Ķ��׵���ֵ������˷ֶκ����Ķ��׵�����ϵ��M( j )
n = length( given_points );

%����ÿ������ĳ��ȣ�������h�洢
h = given_points( 2 : n ) - given_points( 1 : n - 1 );

%�������ԽǾ����ϵ����������a��b�洢
mu = zeros( 1, n - 3 );
lambda = zeros( 1, n - 3 );
mu( 1 : n - 3 ) = h( 2 : n - 2 ) ./ ( h( 2 : n - 2 ) + h( 3 : n - 1 ) );
lambda( 1 : n - 3 ) = h( 2 : n - 2 ) ./ ( h( 1 : n - 3 ) + h( 2 : n - 2 ) );

%�������Է�����ĳ����������d�洢
d = zeros( 1, n - 2 );

d( 1 : n - 2 ) = 6 .* ( ( function_values( 3 : n ) - function_values( 2 : n - 1 ) ) ./ h( 2 : n - 1 ) - ( function_values( 2 : n - 1 ) - function_values( 1 : n - 2 ) ) ./ h( 1 : n - 2 ) ) ./ ( h( 2 : n - 1 ) + h( 1 : n - 2 ) );

%������������

d( 1 ) = d( 1 ) - h( 1 ) / ( h(1) + h(2) ) * S( 1 );
d( n - 2 ) = d( n - 2 ) - h( n - 1 ) / ( h(n-1) + h(n - 2)) * S(2);


% �������ԽǾ���
mid = zeros( 1, n -2 );
mid = mid + 2;
M = diag( mid ) + diag( lambda, 1 ) + diag( mu, -1 );

%������ط��̣��õ�ϵ������
temp_output = M \ d';
output = zeros( 1, n );
output( 2 : n-1 ) = temp_output;
output(1) = S(1);
output(n) = S(2);
end