function [value] = polynomail_eval( args, eval_points, given_points )
%����ʽ��ֵ���������������argsΪ����ʽ��ϵ�������մ����Ӹߵ������У�
%eval_pointsΪҪ��ֵ��������
%����ʽ����(x-x1)(x-x2)(x-x3),����given_pointsΪ�����ĵ�
value = args( length( args ) );
for i = length( args ) - 1:-1:1
    value = value .* ( eval_points - given_points( i ) ) + args( i );
end;

