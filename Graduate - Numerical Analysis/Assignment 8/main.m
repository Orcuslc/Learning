n = 11;
error = zeros((n-1)/2, 1);
xx = (0:1e-4:2*pi)';
plot(xx, exp(sin(xx)));
hold on;
for i = 1:2:n
    t = (0:(2*pi/(i-1)):2*pi)';
    y = exp(sin(t));
    yy = trigonometric(t, y, xx);
    error((i+1)/2) = max(abs(yy-exp(sin(xx))));
    plot(xx, yy);
    hold on;
end
legend('f', 'n=1', 'n=3', 'n=5', 'n=7', 'n=9', 'n=11', 'Location', 'Best');