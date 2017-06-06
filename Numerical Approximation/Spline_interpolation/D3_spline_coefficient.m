function [ output ] = D3_spline_coefficient( given_points, function_values )
%D2_SPLINE_COEFFICIENT �����x_valuesΪ������С����˵㣬f_valuesΪ��������Щ�˵��ϵ�ȡֵ
% SΪ����������������������Ϊ���˵Ķ��׵���ֵ������˷ֶκ����Ķ��׵�����ϵ��M( j )
n = length( given_points );

%����ÿ������ĳ��ȣ�������h�洢
h = given_points( 2 : n ) - given_points( 1 : n - 1 );

%�������ԽǾ����ϵ����������a��b�洢
mu = zeros( 1, n - 1 );
lambda = zeros( 1, n - 1 );
mu( 1 : n - 2 ) = h( 1 : n - 2 ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );
lambda( 1 : n - 2 ) = 1 - mu( 1 : n - 2 );
% h( 2 : n - 1 ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );

%�������Է�����ĳ����������d�洢
d = zeros( 1, n - 1 );
d( 1 : n - 2 ) = 6 * ( ( ( function_values( 3 : n ) - function_values( 2 : n - 1 ) ) ./ h( 2 : n - 1 ) - ( function_values( 2 : n - 1 ) - function_values( 1 : n - 2 ) ) ./ h( 1 : n - 2 ) ) ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );

%������������
lambda( n - 1 ) = h( 1 ) / ( h( 1 ) + h ( n - 1 ) );
mu( n - 1 ) = 1 - lambda( n - 1 );
d( n - 1 ) = 6 * ( ( function_values( 2 ) - function_values( 1 ) ) / h( 1 ) - ( function_values( n ) - function_values( n - 1 ) ) / h( n - 1 ) ) / ( h( 1 ) + h( n - 1 ) );

% �������ԽǾ���
mid = zeros( 1, n - 1 );
mid = mid + 2;
M = diag( mid ) + diag( lambda( 1 : n - 2 ), 1 ) + diag( mu( 2 : n - 1 ), -1 );
M( 1, n - 1 ) = mu( 1 );
M( n - 1, 1 ) = lambda( 1 );

%������ط��̣��õ�ϵ������
temp = M \ d';
output = zeros( 1, n );
output( 1 ) = temp( n - 1 );
output( 2 : n ) = temp;
end