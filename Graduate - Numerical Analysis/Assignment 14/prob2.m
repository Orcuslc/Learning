format long g;

f1 = @(x) exp(-x.^2);
f2 = @(x) x.^2.5;
f3 = @(x) 1./(1+x.^2);
f4 = @(x) 1./(2+cos(x));
f5 = @(x) exp(x).*cos(4*x);

a1 = 0; b1 = 1;
a2 = 0; b2 = 1;
a3 = -4; b3 = 4;
a4 = 0; b4 = 2*pi;
a5 = 0; b5 = pi;

N = 20;
T1 = romberg(f1, a1, b1, N);
T2 = romberg(f2, a2, b2, N);
T3 = romberg(f3, a3, b3, N);
T4 = romberg(f4, a4, b4, N);
T5 = romberg(f5, a5, b5, N);

res = [T1 T2 T3 T4 T5];

dlmwrite('res2.m', res, 'delimiter', ' ', 'precision', '%2.9f');