function [u] = theta(the, tau, T, h, f, u0)
%     theta: the parameter in the theta_scheme;
%     tau: delta t in time step;
%     tmax: max T in time;
%     Nx: number of points in x;
%     f: external force;
    tmax = T/tau; % Max step in time
    n = 1/h; x = 0:h:1;
    delta_h = -1/(h^2) * (diag(ones(1, n+1)*2, 0) + diag(ones(1, n)*-1, -1) + diag(ones(1, n)*-1, -1));
    u = zeros(tmax+1, n+1);
    u(1, :) = u0(x);
    for i = 2:(tmax+1)
        u(i, :) = ((eye(n+1)-tau*the*delta_h)\((eye(n+1)+tau*(1-the)*delta_h)*u(i-1, :)' + tau*(the*f(i*tau, x)' + f((i-1)*tau, x)')))';
    end
    