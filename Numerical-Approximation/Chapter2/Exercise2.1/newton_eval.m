function [func]= newton_eval(n)
    syms x;
    x_values = 1/n * (0 :  n);
    f_values = 1 ./ (1 + (x_values .^ 2) .* 25);
    args = newton_coefficient(x_values, f_values); 
    func = newton_func(args, x_values);
     