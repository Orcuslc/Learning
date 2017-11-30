function res = RK4ND(f, X0, h, t)
% RK4 method in N dimentional case;
% f: cell array of functions;
% X0: 1*N array of initial values;
% h: step size;
% t = [t0, t1]: time periods;

t0 = t(1)-h; t1 = t(2);
N = length(X0); nstep = (t1-t0)/h;
if N ~= length(f)
    error('Dimension of function and initial values do not agree');
end

res = zeros(nstep, N);
for i = 1:nstep
    t0 = t0+h;
    res(i, :) = X0;
    X1 = X0;
    X2 = zeros(1, N);
    for j = 1:N
        X2(j) = feval(f{j}, t0, X1);
    end
    X2 = X0 + h/2*X2;
    X3 = zeros(1, N);
    for j = 1:N
        X3(j) = feval(f{j}, t0+h/2, X2);
    end
    X3 = X0 + h/2*X3;
    X4 = zeros(1, N);
    for j = 1:N
        X4(j) = feval(f{j}, t0+h/2, X3);
    end
    X4 = X0 + h*X4;
    for j = 1:N
        X0(j) = X0(j) + h/6*(feval(f{j}, t0, X1)...
                            + 2*feval(f{j}, t0+h/2, X2)...
                            + 2*feval(f{j}, t0+h/2, X3)...
                            + feval(f{j}, t0+h, X4));
    end
end