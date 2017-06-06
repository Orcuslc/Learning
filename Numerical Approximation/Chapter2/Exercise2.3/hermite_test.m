function [value] = hermite_test()
syms x x1;
func = hermite_eval();
value = subs(x, x1);