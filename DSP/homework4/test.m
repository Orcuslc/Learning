n = 2^13;
m = 20;
[x, y] = sampling([0, 4], n, @(x)(sin(x)));
xindex = randi(n, 1, m);
y(xindex) = y(xindex) + rand(1, m);
[y1, A] = daubechies_decomposite(transpose(y));
A(:, 1:5) = 0;
% A(:, :) = 0;
y2 = daubechies_recomposition(y1, A);
figure(1)
plot(x, transpose(y2));
figure(2)
plot(x, y);
