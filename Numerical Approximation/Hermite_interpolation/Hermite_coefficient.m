function [ output ] = Hermite_coefficient( given_points, function_values )
%求出Hermite插值多项式的系数，其中given_points为输入的插值节点，function_values为输入的函数值或者导数值

% n 为输入的given_points向量的长度
n = length( given_points );
H = zeros( n, n );

% 将输入的f_series中的数（因为其中有f的k阶导数）转化为差商表中的第一列
for i = 1 : n
    H( i, 1 ) = function_values( find( given_points == given_points( i ), 1, 'first' ) );
end;

for i = 2 : n
    for j = 1 : n - i + 1
        % pos1 为x_values( j )第一次出现的位置，pos2为x_values( i + j - 1)
        %第一次出现的位置； 如果pos1 = pos2， 这就意味着这轮循环中x_values( j )
        % = x_values( i + j - 1)，也意味着差商表的这个位置应用导数来代替；
        %导数在f_values中的位置即为pos + j - 1;
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



