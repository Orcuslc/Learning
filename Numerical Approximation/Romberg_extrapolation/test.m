%test of romberg_extrapolation
% 
func = @(x)(exp(x));
inteval = [0, 1];
tolerance = 1e-4;
value = romberg_extrapolation( func, inteval, tolerance );
disp(value);
exact_value = exp(1) - 1;

n = 10;
value_list = zeros(n);
order_list = linspace(1, n, n);
for i = 1:n
    value = romberg_ordered_iteration( func, inteval, order_list(i) );
    value_list(i) = exact_value - value;
end
figure(1);
grid on;
% legend('Residue', 'location', 'best');
semilogy(order_list, -value_list, '*-');
title( {'Residue of integration of exp(x) in [0,1] using romberg extrapolation'} );

m = 20;
value_list2 = zeros(m);
order_list2 = linspace(1, m, m);
func2 = @(x)(1./(1+25.*(x.^2)));
inteval2 = [-1, 1];
exact_value2 = 1/5 * (atan(5) - atan(-5));
for i = 1:m
    value = romberg_ordered_iteration( func2, inteval2, order_list2(i) );
    value_list2(i) = exact_value2 - value;
end
figure(2);
grid on;
semilogy(order_list2, value_list2, '*-');
title('Residue of integration of (1/(1+25x^2)) in [-1, 1] using romberg extrapolation');
% %exercise9.1
% % func = @(x)(exp(x.^2));
% % order = 10;
% % inteval = [0, 1];
% % value = composite_simpson_quad( func, inteval, order );
% % disp(value);
% % value2 = romberg_ordered_iteration( func, inteval, order );
% % disp(value2);
% 
% %exercise9.2
% func = @(x)((1-cos(x))./x);
% order = 9;
% inteval = [0, pi];
% value = composite_simpson_quad( func, inteval, order );
% disp(value);
% value2 = romberg_ordered_iteration( func, inteval, order );
% disp(value2);