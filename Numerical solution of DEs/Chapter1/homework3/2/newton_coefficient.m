function [ value ] = newton_coefficient( given_points, function_values )
%���ţ�ٲ�ֵ����ʽ��ϵ��������given_pointsΪ�����Ĳ�ֵ������꣬function_valuesΪ��������
        n = length(function_values);
        for i =1: n - 1
            function_values(i+1:n) = (function_values(i+1:n) - function_values(i:n - 1)) ./ (given_points(i+1:n) - given_points(1:n - i));
%             disp(f_values(i:n));
        end
        value = function_values;
    