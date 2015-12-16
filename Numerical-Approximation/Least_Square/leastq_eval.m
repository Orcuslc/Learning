function [ value ] = leastq_eval( args, eval_points_x )
%����ʽ��ֵ���������������argsΪ����ʽ��ϵ������������ϵ����Ӧ�Ĵ����ӵ͵�������
%eval_points_xΪҪ��ֵ��ĺ����꣬��һ����������ʾ

%��eval_points��ʾ����
%[ 1, x1, x1^2, ..., x1^n ]
%[ 1, x2, x2^2, ..., x2^n ]
%...
%[ 1, xk, xk^2, ..., xk^n ]
%����ʽ

m = length( eval_points_x );
n = length( args );
M = zeros( m, n );
M( : , 1 ) = 1;
M( : , 2 ) = eval_points_x;


for i = 3 : n
    M( : , i ) = M( : , i - 1 ) .* eval_points_x;
end

value = M * args;


