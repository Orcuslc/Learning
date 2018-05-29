c = zeros(11, 1);
x = 0.426302751006863;

g = @(x) (-exp(-x) - 0.5/sqrt(x));
f = @(x)(exp(-x)-sqrt(x));

x0 = 0.7; x1 = x0-f(x0)/g(x0);
c(1) = x0; c(2) = x1;
for k = 2:10
    c(k+1) = c(k) - f(c(k))*(c(k)-c(k-1))/(f(c(k))-f(c(k-1)));
end
err = abs(c - x);