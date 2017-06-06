%test_dichotomy
format long
% func = @(x)(x.^3 - 5.* x +4.272);
% a = 1;
% b = 1.3;
% root = dichotomy(func, a, b, 1e-4);
% disp(root);
% 

% exercise 7.4
% func = @(x)(x.^3 - 5*x.^2 +3.89 * x +0.804);
% a = 1; b = 2;
% root = dichotomy(func, a, b);
% disp(root);
% 
func = @(x)(x.^3 - 5*x.^2 +4.272);
a = 1; b = 1.3;
root = dichotomy(func, a, b);
disp(root);

% func = @(x)(x - exp(-x));
% a = 0; b = 1;
% root = dichotomy(func, a, b);
% disp(root);
% % 
func = @(x)(0.8+0.2*sin(x));
x0 = 0.8;
root = fixed_point_iter(func, x0, 1e-16);
disp(root);

% func = @(x)(exp(-x));
% x0 = 0.567187;

func = @(x)(0.8 + 0.2*sin(x));
x0 = pi;
dfx0 = -0.2;
root = simplified_newton_iter(func, x0, dfx0);

func = @(x)(0.8 + 0.2 * sin(x));
x0 = pi;
x1 = pi / 4 * 3;
root = secant_iter(func, x0, x1);