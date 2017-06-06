function [ coeff_vector ] = leastq_coeff( points, order )
%LEASTQ ����������N*2����points, �Լ���ϵĽ���order, ������order << N��
%�����ϵ�ϵ����������coeff_vector��ʾ

if ( sort( points( : , 1 ) , 'ascend' ) ~= points( : , 1 ) )
    error( ' Points are not in ascend order ' );
end

N = length( points );

%��ʼ�������̵�ϵ������
X = zeros( N, order + 1 );
X( : , 1 ) = 1;
X( : , 2 ) = points( : , 1 );
for i = 3 : order + 1
    X( : , i ) = X( : , i - 1 ) .* points( : , 1 );
end

%���취���̣��������
Y = transpose( X );
coeff_vector = ( Y * X ) \ ( Y * points( : , 2 ) );


