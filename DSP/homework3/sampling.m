function [x, y] = sampling(num)
% Sampling of a signal;
% func : The function of the signal;
% interval : The sampling interval of the signal;
% num : The number of points, MUST BE the power of 2;

% len = interval(2) - interval(1);
% n = num - 1;
% delta = len/n;
% x = interval(1):delta:interval(2);
% y = feval(func, x);
snr = 3;
init = 342478682;
[~, y] = wnoise(3, num, snr, init);
x = 0:1:2^num-1;

end

