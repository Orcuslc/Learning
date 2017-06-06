function [ parameters ] = parametrize( points )
%PARAMETIZE 将一列点进行参数化
%输入的points为一个2 * n的矩阵， 输出的parameters为一个1 * n的行向量
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

