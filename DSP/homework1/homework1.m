h1 = [1, 1];
% h2 = [1, -1];
% f = @(x)(sin(10*x));
n = 201;
x = 0:1/(n-1):1;
f = sin(8*x) + rand(1, n) * 0.1 + 2 * sin(x);

figure(1);
title('homework1');
plot(x, f, 'r-');
hold on;

% y1 = convolution(f, h1);
y1 = convolution(f, h1);
y1 = y1(1:length(y1) - 1);
plot(x, y1, 'g-');
hold on;

% % y2 = convolution(f, h2);
% y2 = conv(f, h2);
% y2 = y2(2:length(y2));
% plot(x, y2, 'b-');
% hold on;
title('Medium Operator');
legend('The signal with random', 'The signal handled by [1, 1]', 'Location', 'Best');
