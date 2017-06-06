function [func]= newton_eval(n)
    syms x;
    tic;
    x_values = 2*pi/n * (0 :  n);
    f_values = sin(x_values);
%     x_values = [0.4, 0.5, 0.7, 0.8];
%     f_values = log(x_values);
    args = newton_coefficient(x_values, f_values); 
    func = collect(newton_func(args, x_values));
    toc;
     