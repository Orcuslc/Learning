format long
func1 = @(x)(sin(x));
func2 = @(x)(cos(x));
x0 = pi*3/4;
tol = 1e-8;
n = 10;
residue = [];
order_list = linspace( 1, n, n);
for i = 1 : n
    residue(i) = abs(pi - newton_iter(func1, func2, x0, tol, order_list(i)));
end
semilogy(order_list, residue);