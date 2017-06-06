function [ parameters ] = parametrize( points )
%PARAMETIZE ��һ�е���в�����
%�����pointsΪһ��2 * n�ľ��� �����parametersΪһ��1 * n��������
n = length( points );
 d = zeros( 1, n-1 );
 d = sqrt( (points( 1, 2 : n ) - points( 1, 1 : n - 1 )) .^ 2 + (points( 2, 2 : n ) - points( 2, 1 : n - 1 )) .^ 2);
 parameters = zeros( 1, n );
 d_total_sum = sum(d);
 d_sum = 0;
 for i = 1 : n - 1
     d_sum = d_sum + d( i );
     parameters( i  + 1 ) = d_sum / d_total_sum;
end

