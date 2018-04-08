function y = h(s, N)
dx = 2/N;
f = @(x) (x<2)-(x<=0);
x = (0:(N-1))*dx;
y = dx*sum(f(x) .* exp(-1i.*x*s));