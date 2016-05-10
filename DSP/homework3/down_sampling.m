function [x] = down_sampling(xx)
% DOWN_SAMPLING 
n = length(xx);
x = xx(2:2:n);
end

