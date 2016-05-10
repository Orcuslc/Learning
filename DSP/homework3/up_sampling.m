function [x] = up_sampling(xx)
% UP_SAMPLING 

n = length(xx);
x = zeros(1, 2*n);
x(2:2:2*n) = xx;

end

