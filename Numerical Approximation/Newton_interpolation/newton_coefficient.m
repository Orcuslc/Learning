function [ value ] = newton_coefficient( given_points, function_values )
%求出牛顿插值多项式的系数，其中given_points为给定的插值点横坐标，function_values为其纵坐标
        n = length(function_values);
        for i =1: n - 1
            function_values(i+1:n) = (function_values(i+1:n) - function_values(i:n - 1)) ./ (given_points(i+1:n) - given_points(1:n - i));
%             disp(f_values(i:n));
        end
        value = function_values;
    