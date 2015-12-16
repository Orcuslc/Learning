function [value] = newton_eval()
    j = [0.2, 0.28, 0.36, 0.44, 0.52, 0.6, 0.68, 0.76, 0.84, 0.92, 1.00];
    for i = 1: length(j)
        j(i) = newton_func(j(i));
    end;
    value = j;



function [value] = newton_func(n)
    f = [0.98, 0.92, 0.81, 0.64, 0.38];
    x = [0.2, 0.4, 0.6, 0.8, 1.0];
    value = f(1);
    coef = get_coefficient(x, f);
    for i = 2:length(f)
        temp = 1;
        for j = 1:i-1
            temp = temp * (n-x(j));
        end;
        value = value + coef(i) * temp;
    end;
    

function [value_array] = get_coefficient(x, f)
    for i = 1:length(f) - 1
        f(i+1:length(f)) = (f(i+1:length(f)) - f(i:length(f) - 1)) ./ (x(i +1:length(x)) - x(1:length(x) - i));
    end;
    value_array = f;