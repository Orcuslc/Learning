x = 0:0.01:15;

%%% (a)
% plot(x, u(x, 0.5));

%%% (b)(1)
delta_t = 0.05;
t = 1.5;
plot(x, u(x, t)); hold on;
plot(x, u(x, t+delta_t));