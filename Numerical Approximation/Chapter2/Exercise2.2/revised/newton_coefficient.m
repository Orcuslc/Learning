function [f_values] = newton_coefficient(x_values, f_values)
        n = length(f_values);
        for i =1: n - 1
            f_values(i+1:n) = (f_values(i+1:n) - f_values(i:n - 1)) ./ (x_values(i+1:n) - x_values(1:n - i));
        end
%         value = f_values;
    