% Initial Conditions
format long;
q0 = pi/8; p0 = 0; t0 = 0;
h = 0.01; N = 1000;

% The Hamiltonian Function
H = @(p, q)((p.^2)./2-cos(q)); 

[q1, p1, t1] = Explicit_Euler(q0, p0, t0, h, N);
[q2, p2, t2] = Partitioned_Euler_I(q0, p0, t0, h, N);

subplot(211);
plot(t1, H(p1, q1), '-.');
title('Explicit Euler Format');
legend('H', 'Location', 'Best');
grid on;

subplot(212);
plot(t2, H(p2, q2), '-.');
title('Partitioned Euler I');
legend('H', 'Location', 'Best');
grid on;