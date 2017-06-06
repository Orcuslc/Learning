function [ value ] = composite_simpson_quad( func, inteval, order )
% Calculate the intergration of func with composite simpson quad
% func: the function to integrate; inteval: the inteval to integrate on;
% order: the order of the quad;

if nargin < 2
    error('more args are needed --composite simpson quad');
elseif nargin == 2
    order = 4;
    %Set the default order = 4, if it is not inputted.
end

a = inteval(1);
b = inteval(2);
if a == b
    value = 0;
    return;
elseif a > b
    error('inteval should have a positive length --composite simpson quad');
end

value = ( 4 *romberg_ordered_iteration( func, inteval, order * 2 ) - romberg_ordered_iteration( func, inteval, order )) / 3;



end

