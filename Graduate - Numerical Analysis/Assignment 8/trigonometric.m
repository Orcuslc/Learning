function yy = trigonometric(t, y, xx)
% Trigonometric Interpolation
% t, y: Interpolation points and function values;
% xx: points to evaluate function values;
n = (length(t)-1)/2;
M = zeros(2*n+1, 2*n+1);
for i = 1:(2*n+1)
    M(i, :) = exp(1i*t(i)).^(-n:1:n);
end
C = M\y;

xx = exp(1i*xx);
yy = ones(length(xx), 1)*C(end);
for i = (2*n):-1:1
    yy = yy.*xx+C(i);
end
yy = yy./(xx.^n);
