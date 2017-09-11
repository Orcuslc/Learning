function [q, p, t] = Partitioned_Euler_I(q0, p0, t0, h, N)
% Partitioned Euler I format for the Hamiltonian system;
% (q0, p0, t0): initial conditions;
% h: step length; 
% N: number of steps;
   q = zeros(N+1, 1); q(1) = q0;
   p = zeros(N+1, 1); p(1) = p0;
   t = t0 + h.*(0:1:N);
   for i = 1:N
       p(i+1) = p(i)-h*sin(q(i));
       q(i+1) = q(i)+h*p(i+1);
   end