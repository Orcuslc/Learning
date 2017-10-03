function [q, p] = partitioned_Euler_2(f, g, q0, p0, h, N)
% Partitioned Euler II for 2d cases;
% f, g: functions;
% q0, p0: init values;
% h: step length; N: iteration numbers;
% For the problem itself;
q = zeros(N+1, 1); p = zeros(N+1, 1);
q(1) = q0; p(1) = p0;
for i = 1:N
    q(i+1) = q(i)/(1-h*(p(i)-3));
    p(i+1) = p(i)*(1+h*(2-q(i+1)));
end