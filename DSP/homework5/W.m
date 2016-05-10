function [ w ] = W( N )
% W
% The function to return the rotate factor in FFT.
w = exp(-1i*2*pi * 1/(1:N));

end

