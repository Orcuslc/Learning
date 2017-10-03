function [q, p] = explicit_Euler(f, g, q0, p0, h, N)
% Explicit Euler for 2d cases;
% f, g: functions;
% q0, p0: init values;
% h: step length; N: iteration numbers;
q = zeros(N+1, 1); p = zeros(N+1, 1);
q(1) = q0; p(1) = p0;
for i = 1:N
    q(i+1) = q(i)+h*feval(f, q(i), p(i));
    p(i+1) = p(i)+h*feval(g, q(i), p(i));
end

    