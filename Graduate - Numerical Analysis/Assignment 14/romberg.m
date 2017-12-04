function T = romberg(f, a, b, n)
% Romberg extrapolation
% f: function
% x: interval: [a, b]
% n: order
T = zeros(n, n);
T(1, 1) = (feval(f, a)+feval(f, b))/2*(b-a);

for i = 2:n
    k = 2^(i-1);
    h = (b-a)/k;
    eval_points = a + (2*linspace(1, k, k)-1)*h/2;
    sums = sum(feval(f, eval_points));
    T(i, 1) = 0.5*(h*sums + T(i-1, 1));
    m = 1;
    for j = 2:i
        m = m*4;
        T(i, j) = (m*T(i, j-1)-T(i-1, j-1))/(m-1);
    end
end

T = diag(T);