function [ freq, powers ] = power_spectrum( time, signal, method )
% POWER_SPECTRUM
% Calculate the power spectrum of the input signal list;
% Time: the time points of sampling;
% Method: 'p', periodogram method or 'ac',  auto-correlation method;
% Return: freq, the freq list, and powers, the power for each freq;

if nargin < 2
    error('More args needed');
elseif nargin == 2
    method = 'p';
end

N = length(signal);
freq = (time(N)-time(1)) * (0:ceil(N/2)-1) / ((N-1)^2);


if method == 'p'
    y = fft(signal);
    powers = (y .* conj(y))/(N-1);
    powers = powers(1:ceil(N/2));
end

