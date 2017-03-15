% homework 1.2.1
format long

f = @(x)(x - exp(-x));
f2 = @(x)(1 + exp(-x));
g = @(x)(exp(-x));

x0 = 0.6;
tol = 1e-16;
n1 = 4;
n2 = 24;
[root1, root_list1] = fixed_point_iter(g, x0, tol, n2);
[root2, root_list2] = newton_raphson_iter(f, f2, x0, tol, n1);
% 
% disp('root1')
% disp(root1)
% disp('root_list1')
% disp(root_list1)
% disp('root2')
% disp(root2)
% disp('root_list2')
% disp(root_list2)

figure(1);
xx = 0.5:1e-4:0.6;
% plot(xx, xx); hold;
f2 = @(x)(exp(-x));
g2 = @(x)(exp(-x));
plot(xx, f2(xx)); hold;
plot(root_list1, f(root_list1), '*', 'MarkerSize', 2)