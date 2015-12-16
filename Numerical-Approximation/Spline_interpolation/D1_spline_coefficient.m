function [ output ] = D1_spline_coefficient( given_points, function_values, S )
%D1_SPLINE_COEFFICIENT �����given_pointsΪ������С����˵㣬f_valuesΪ��������Щ�˵��ϵ�ȡֵ
% SΪ����������������������Ϊ���˵�һ�׵���ֵ������˷ֶκ����Ķ��׵�����ϵ��M( j )
n = length( given_points );

%����ÿ������ĳ��ȣ�������h�洢
h = given_points( 2 : n ) - given_points( 1 : n - 1 );

%�������ԽǾ����ϵ����������a��b�洢
mu = zeros( 1, n - 1 );
lambda = zeros( 1, n - 1 );
mu( 1 : n - 2 ) = h( 1 : n - 2 ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );
lambda( 2 : n - 1 ) = h( 2 : n - 1 ) ./ ( h( 1 : n - 2 ) + h( 2 : n - 1 ) );

%�������Է�����ĳ����������d�洢
d = zeros( n, 1 );
d( 2 : n - 1 ) = 6 * (( function_values( 3 : n ) - function_values( 2 : n - 1 ) ) ./ h( 2 : n - 1 ) - ( function_values( 2 : n - 1 ) - function_values( 1 : n - 2 ) ) ./ h( 1 : n - 2 )) ./ ( h( 2 : n - 1 ) + h( 1 : n - 2 ) );

%������������
mu( n - 1 ) = 1;
lambda( 1 ) = 1;
d( 1 ) = 6 / h( 1 ) * ( ( function_values( 2 ) - function_values( 1 ) ) / h( 1 ) - S( 1 ) );
d( n ) = 6 / h( n - 1 ) * ( S( 2 ) - ( function_values( n ) - function_values( n - 1 ) ) / h( n - 1 ) );

% �������ԽǾ���
mid = zeros( 1, n );
mid = mid + 2;
M = diag( mid ) + diag( lambda, 1 ) + diag( mu, -1 );

% disp(M);
% disp(d);
%������ط��̣��õ�ϵ������
output = M \ d;
% disp(output);

end

