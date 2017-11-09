q0 = 1.8; p0 = 3.4;
N = 500; h = 0.05;
f = @(f, r)(f*(r-3));
g = @(f, r)(r*(2-f));

I = @(f, r)(f-2*log(f)+r-3*log(r));

[q1, p1] = explicit_Euler(f, g, q0, p0, h, N);
[q2, p2] = partitioned_Euler_2(f, g, q0, p0, h, N);
I1 = I(q1, p1);
I2 = I(q2, p2);

figure(1);
plot(q1, p1);
title('Explicit Euler, Solution');
grid on;

figure(2);
plot(q2, p2);
title('Partitioned Euler 2, Solution');
grid on;

figure(3);
plot3(q1, p1, I1);
title('Explicit Euler, I');
grid on;

figure(4);
plot3(q2, p2, I2);
title('Patitioned Euler 2, I');
grid on;