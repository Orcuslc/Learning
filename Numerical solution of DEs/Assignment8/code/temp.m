%calculation of relative error
%we just consider the situation about a = 1 b = 10 c = 10
%compute -a*d^2u/dx^2+b*du/dx+cu = 1 by three-point difference
%still use the central difference to approximate the derivative

E = zeros(1,6);
% DT = [0.0005 0.001 0.005 0.01 0.05];
DT = (0.5.^(1:6));
T = log10(DT);
for M =1:6
    dt = DT(M);
    t = 0:dt:1;
%     N = 1/dt;
    N = length(t)-1;
    A = diag(-2*ones(N-1,1))+diag(ones(N-2,1),-1)+diag(ones(N-2,1),1);
    A = -(1/(dt^2))*A;
    B = diag(-1*ones(N-2,1),-1)+diag(ones(N-2,1),1);
    B = (0.5/dt)*B;
    C = diag(ones(N-1,1));
    f = ones(1,N-1);
    a = 1;
    b = 10;
    c = 10;
    v1 = (-b+sqrt(b^2+4*a*c))/(-2*a);
    v2 = (-b-sqrt(b^2+4*a*c))/(-2*a);
    u = (exp(v2)-1-v1)*exp(v1*t)/(c*((1+v2)*exp(v1)-(1+v1)*exp(v2)))+...
        (exp(v1)-1-v2)*exp(v2*t)/(c*((1+v1)*exp(v2)-(1+v2)*exp(v1)))+1/c;
    A = a*A;
    B = b*B;
    C = c*C;
    f(1) = f(1)+a*(1/(dt^2))*u(1)+(b/(2*dt))*u(1);
    f(N-1) = f(N-1)+a*(1/(dt^2))*u(N+1)+(b/(2*dt))*u(N+1);
    uh = ((A+B+C)^(-1)*f')';
    uh = [u(1) uh u(N+1)];
    K = abs((uh-u)./u);
    E(M) = max(K);
end
loglog(DT,E,'*-');
title('Relative error');