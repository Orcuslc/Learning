function [ ]  = Newton_eval( given_points, function_values, eval_points)
%NEWTON_EVAL  ����ţ�ٲ�ֵ����ʽ�����������һЩ��Ľ���ֵ��������ͼ��
%   x_values��f_values��������йز�ֵ������x_seriesΪ�������ֵ��
    
%����newton_coefficient�������Newton��ֵ����ʽ�ĸ���ϵ�����ӵ͵�������
args = newton_coefficient( given_points, function_values );

%����polynimail_eval���������������ʽ��X�����ֵ������XΪ�����������ݵ�
f_series = polynomail_eval(args, eval_points, given_points);

%����ͼ��
plot( eval_points, f_series );


