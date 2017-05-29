f = @(t, x)(sin(pi*x)*exp(-t^2));
u0 = @(x)(sin(pi*x));
the = 0;
tau = 1e-3;
T = 0.1;
h = 1e-2;
u = theta(the, tau, T, h, f, u0);
surf(0:h:1, 0:tau:T, u);
xlabel('x'); ylabel('t'); zlabel('u');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%