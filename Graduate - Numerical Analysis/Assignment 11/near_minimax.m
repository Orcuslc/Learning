function res = near_minimax(f, g, n, xx)
% near minimax approximation using lagrange form
% f: the function to approximate
% g: the map of [0, 1] to the desired interval
% n: order
% xx: eval points

x = feval(g, cos((2*(0:n)+1)./(2*n+2)*pi));
xx = feval(g, xx);
res = zeros(1, length(xx));

for i = 1:(n+1)
        tmp = zeros(1, length(xx))+1;
        for j = 1:(n+1)
            if j ~= i
                tmp = tmp.*(xx - x(j))./(x(i)-x(j));
            end
        end
        res = res + tmp*feval(f, x(i));
end
