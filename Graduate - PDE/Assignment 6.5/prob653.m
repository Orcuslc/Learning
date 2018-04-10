s = -4*pi:1e-4:4*pi;
l = length(s);

Y = zeros(6, l);
N = [1, 5, 10, 50, 100, 500];
for d = 1:6
    for i = 1:l
        Y(d, i) = h(s(i), N(d));
    end
end

f_hat = @(s) (1i./s.*(cos(2*s)-1) + sin(2*s)./s);

subplot(211)
plot(s, real(f_hat(s))); hold on;
for d = 1:6
    plot(s, real(Y(d, :))); hold on;
end
legend('f', 'N=1', 'N=5', 'N=10', 'N=50', 'N=100', 'N=500');
title('Real part');

subplot(212)
plot(s, imag(f_hat(s))); hold on;
for d = 1:6
    plot(s, imag(Y(d, :))); hold on;
end
legend('f', 'N=1', 'N=5', 'N=10', 'N=50', 'N=100', 'N=500');
title('Imag part');