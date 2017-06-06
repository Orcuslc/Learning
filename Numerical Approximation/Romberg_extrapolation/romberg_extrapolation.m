function [ value ] = romberg_extrapolation( func, inteval, tolerance )
% Calculate the integration using Romberg Extrapolation
% func: the function to integrate, inteval: the inteval to integrate on,
% tolerance: the tolerance between the last two results

if nargin < 2
    error('more args are needed --romberg extrapolation');
elseif nargin == 2
    tolerance = 1e-4;
    %Set the default tolerance = 1e-6, if it is not inputted.
end

a = inteval(1);
b = inteval(2);
if a == b
    value = 0;
    return;
elseif a > b
    error('inteval should have a positive length --romberg extrapolation');
end

value = romberg_iteration(func, inteval, tolerance);



end

