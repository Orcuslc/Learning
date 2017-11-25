f1 = @(x) exp(-x.^2);
a1 = 0; b1 = 1;
g1 = @(x) (-2*x.*f1(x));

f2 = @(x) x.^2.5;
a2 = 0; b2 = 1;
g2 = @(x) 2.5.*(x.^1.5);

f3 = @(x) 1./(1+x.^2);
a3 = -4; b3 = 4;
g3 = @(x) -2*x./((1+x.^2).^2);

f4 = @(x) 1./(2+cos(x));
a4 = 0; b4 = 2*pi;
g4 = @(x) sin(x)./((2+cos(x)).^2);

f5 = @(x) exp(x).*cos(4*x);
a5 = 0; b5 = pi;
g5 = @(x) exp(x).*(cos(4*x)-4*sin(4*x));

N = 9;
res = zeros(N, 5);
n = 2.^(1:N);
for i = 1:N
    res(i, 1) = trapezoidal(f1, a1, b1, n(i));
    res(i, 2) = trapezoidal(f2, a2, b2, n(i));
    res(i, 3) = trapezoidal(f3, a3, b3, n(i));
    res(i, 4) = trapezoidal(f4, a4, b4, n(i));
    res(i, 5) = trapezoidal(f5, a5, b5, n(i));
end
convergence_rate = zeros(N, 5);
convergence_rate(1:N, 1) = convergence(f1, a1, b1, N, 'trapezoidal');
convergence_rate(1:N, 2) = convergence(f2, a2, b2, N, 'trapezoidal');
convergence_rate(1:N, 3) = convergence(f3, a3, b3, N, 'trapezoidal');
convergence_rate(1:N, 4) = convergence(f4, a4, b4, N, 'trapezoidal');
convergence_rate(1:N, 5) = convergence(f5, a5, b5, N, 'trapezoidal');
 
for i = 1:N
    res(i, 1) = simpson(f1, a1, b1, n(i));
    res(i, 2) = simpson(f2, a2, b2, n(i));
    res(i, 3) = simpson(f3, a3, b3, n(i));
    res(i, 4) = simpson(f4, a4, b4, n(i));
    res(i, 5) = simpson(f5, a5, b5, n(i));
end
convergence_rate = zeros(N, 5);
convergence_rate(1:N, 1) = convergence(f1, a1, b1, N, 'simpson');
convergence_rate(1:N, 2) = convergence(f2, a2, b2, N, 'simpson');
convergence_rate(1:N, 3) = convergence(f3, a3, b3, N, 'simpson');
convergence_rate(1:N, 4) = convergence(f4, a4, b4, N, 'simpson');
convergence_rate(1:N, 5) = convergence(f5, a5, b5, N, 'simpson');

for i = 1:N
    res(i, 1) = corrected_trapezoidal(f1, g1, a1, b1, n(i));
    res(i, 2) = corrected_trapezoidal(f2, g2, a2, b2, n(i));
    res(i, 3) = corrected_trapezoidal(f3, g3, a3, b3, n(i));
    res(i, 4) = corrected_trapezoidal(f4, g4, a4, b4, n(i));
    res(i, 5) = corrected_trapezoidal(f5, g5, a5, b5, n(i));
end
convergence_rate = zeros(N, 5);
convergence_rate(1:N, 1) = convergence(f1, a1, b1, N, 'corrected_trapezoidal', g1);
convergence_rate(1:N, 2) = convergence(f2, a2, b2, N, 'corrected_trapezoidal', g2);
convergence_rate(1:N, 3) = convergence(f3, a3, b3, N, 'corrected_trapezoidal', g3);
convergence_rate(1:N, 4) = convergence(f4, a4, b4, N, 'corrected_trapezoidal', g4);
convergence_rate(1:N, 5) = convergence(f5, a5, b5, N, 'corrected_trapezoidal', g5);