% function [value] = newton_eval()
%     j = [0.2, 0.28, 0.36, 0.44, 0.52, 0.6, 0.68, 0.76, 0.84, 0.92, 1.00];
%     value = newton_func(j);
%     disp(value);



function [value] = newton_eval(n)
% % %     f = [1000.000, 499.999, 333.332, 249.999, 199.998];
% %     x = [0.001, 0.002, 0.003, 0.004, 0.005];
% % %     f = [0.001, 0.002, 0.003, 0.004, 0.005];
% %     f = [1, 0.999998, 0.999996, 0.999992, 0.999988];
% x = [0, 1.5, 3.4, 6.8];
% f = [1.45, 3.14, 4.65, 4.11];
%     n = sym('n');
% x = [14, 17, 31, 35];
% f = [68.7, 64.0, 44.0, 39.1];
x = [0, 1, -1];
f = [1, 3, 1/3];
    value = f(1);
    coef = get_coefficient(x, f);
    for i = 2:length(f)
        temp = 1;
        for j = 1:i - 1
            temp = temp * (n-x(j));
        end;
        value = value + coef(i) * temp;
    end;
    

function [value_array] = get_coefficient(x, f)
    for i = 1:length(f) - 1
        f(i+1:length(f)) = (f(i+1:length(f)) - f(i:length(f) - 1)) ./ (x(i +1:length(x)) - x(1:length(x) - i));
    end;
    value_array = f;