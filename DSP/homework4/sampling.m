function [x, y] = sampling(interval, num, func)
% Sampling of a signal;
% func : The function of the signal;
% interval : The sampling interval of the signal;
% num : The number of points, MUST BE the power of 2;

len = interval(2) - interval(1);
n = num - 1;
delta = len/n;
x = interval(1):delta:interval(2);
y = feval(func, x);


end

