function [ dft_x ] = dft_func( x_series )
%DFT_FUNC function of dft with x_series as input and 1*N matrix dft_x as
%output

N = length(x_series);
n = 0:N-1;
k = 0:N-1;
c = exp(-1i*2*pi/N);
M1 = transpose(n) * k;
M2 = c .^ M1;
dft_x = x_series * M2;
end

