h1 = [1, 1];
h2 = [1, -1];
% f = @(x)(sin(10*x));
n = 201;
x = 0:1/(n-1):1;
f = sin(10*x) + rand(1, n) + 4 * sin(x);

figure(1);
title('homework1');
plot(x, f, 'r-o');
hold on;

y1 = convolution(f, h1);
row_y1 = size(y1);
row_y1 = row_y1(1);
xx1 = 0:1/(row_y1-1):1;
plot(xx1, y1, 'g*-');
hold on;

y2 = convolution(f, h2);
row_y2 = size(y2);
row_y2 = row_y2(1);
xx2 = 0:1/(row_y2-1):1;
plot(xx2, y2, 'b.-');
hold on;

legend('The signal with random', 'The signal handled by [1, 1]', 'The signal handled by [-1, 1]','Location', 'Best');
