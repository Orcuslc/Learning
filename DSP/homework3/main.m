% func = @(x)(sin(x) + 1/3 * sin(2*x) - 0.4 * sin(3*x) + sin(6*x));
% errorfunc = @(x)(5*sin(1000*x));

interval = [0, 2*pi];
num = 12;
[x, y] = sampling(num);
J = 5;

[A, B] = haar_decomposition(x, y, J);
B = filtering(B, 1);
yy = haar_reconstruction(A, B);
plot(x, y, 'g');
hold on;
% plot(x, yy, 'r');
stairs(x, yy, 'r');
