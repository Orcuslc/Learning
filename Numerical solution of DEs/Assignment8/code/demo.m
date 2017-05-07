h = 1e-2;
t = 0:h:1;
N = length(t);
a = 1; b = 10; c = 10;
u_accu = accurate(a, b, c, t);
u_diff = three_point_diff(a, b, c, N-1, u_accu(1), u_accu(N));
u_diff = [u_accu(1), u_diff, u_accu(N)];

figure(1);
plot(t, u_accu, '*-'); hold on;
plot(t, u_diff, '.-');
legend('Accurate', 'Numerical', 'Location', 'Best');

figure(2);
T = 3;
err = zeros(1, T);
% step = (2.^(-3:-1:-10));
step = (0.1.^(1:T));
for i=1:T
    h = step(i);
    t = 0:h:1;
    u_accu = accurate(a, b, c, t);
    N = length(t);
    disp(N)
    u_diff = three_point_diff(a, b, c, N-1, u_accu(1), u_accu(N));
    u_diff = [u_accu(1), u_diff, u_accu(N)];
    err(i) = max(abs((u_diff - u_accu)./u_accu));
end
loglog(step, err);