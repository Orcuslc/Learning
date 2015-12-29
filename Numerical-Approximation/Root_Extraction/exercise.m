format long

n = 100000;
a = rand(1, n) + 1;
b = rand(1, n) + 2;
count = 0;
coeff = zeros(1, 10);
for i = 1:10
    coeff(i) = nchoosek(9, i-1) * (-2) ^ (10 - i);
end

func = @(x)(coeff(1).*x.^0 + coeff(2).*x.^1 +coeff(3).*x.^2 +coeff(4).*x.^3 +coeff(5) .* x.^4 + coeff(6) .* x.^5 +coeff(7).*x.^6+coeff(8) .* x.^7 +coeff(9).*x.^8 +coeff(10).*x.^9);
func2 = @(x)((x-2).^9);
x = zeros(1, 1000);
count2 = 0;
while count <= 1000
    [xi, info] = dichotomy(func2, a(i), b(i));
    if info == 1
       count = count + 1;
       x(count) = xi;
    else
        count2 = count2 + 1;
    end
end
disp(count2);
% x = linspace(1.9, 2.1, 1e4);
% grid on;
% hold on;
% fx = feval(func, x);
% y = (x-2) .^ 9;
% plot(x, fx, '.');
% hold on;
% plot(x, y, 'r');
% axis([0, 4, -1e-11, 1e-11]);
    avgx = mean(x);
    varx = var(x);
    disp(avgx);
    disp(varx);