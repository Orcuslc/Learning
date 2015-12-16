function[func] = hermite_eval()
syms x1 x2 f1 f2 f3 f4 f5
x_values = [x1, x1, x1, x2, x2];
f_values = [f1, f2, f3, f4, f4];
args = hermite_coefficient(x_values, f_values);
func = collect(hermite_func(args, x_values));
% disp(func);