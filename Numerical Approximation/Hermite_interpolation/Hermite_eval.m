function [  ] = Hermite_eval( given_points, function_values, eval_points )
%HERMITE_EVAL ��Hermite��ֵ����ʽ�����������һЩ��Ľ���ֵ��������ͼ��
%   x_values��f_values��������йز�ֵ������x_seriesΪ�������ֵ��

%����Hermite_coefficient�������Newton��ֵ����ʽ�ĸ���ϵ�����ӵ͵�������
args = Hermite_coefficient( given_points, function_values );

%����polynimail_eval���������������ʽ��X�����ֵ������XΪ�����������ݵ�
f_series = polynomail_eval(args, eval_points, given_points);

%����ͼ��
plot( eval_points, f_series );
hold on;
plot( given_points, function_values, 'd');
end


