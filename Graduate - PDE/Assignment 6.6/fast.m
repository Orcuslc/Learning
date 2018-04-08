function [d0, d] = fast(N)
delx = 2*pi/N;
xsample = 0:delx:2*pi-delx;
u = f(xsample); u(1) = pi;
v = fft(u)/N;
d0 = v(1); d = v(2:end);
% x = 0:pi/100:2*pi;
% sum = d0*ones(size(x));
% for k = 1:N/2-1 
%     sum = sum + d(k)*exp(1i*k*x) + d(N-k)*exp(-1i*k*x);
% end
% M = max(real(sum)) + .5; m = min(real(sum)) - .5;
% plot(x,f(x),x,sum)
% axis([0 2*pi m M])
