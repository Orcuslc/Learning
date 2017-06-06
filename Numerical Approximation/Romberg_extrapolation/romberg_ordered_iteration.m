function [ value ] = romberg_ordered_iteration( func, inteval, order )
% Iteration of romberg extrapolation with order given

low = inteval(1);
high = inteval(2);

T = [ feval(func, low) + feval(func, high) ] / 2 * (high - low);
n = 1;

while n <= order
    n = n + 1;
    new_points = low + ( 2 * linspace( 1, 2 ^(n-1) , 2^(n-1) ) - 1 ) * (high - low) / (2 ^ n);
    T( n, 1 ) = 0.5 * ( T( n-1, 1 ) + (high - low) / ( 2 ^ (n-1) ) * sum( feval( func, new_points ) ) );
    for i = 2 : n
        T( n, i ) = ( 4 ^ (i - 1) * T(n, i - 1) - T(n - 1, i - 1) ) / ( 4 ^ (i - 1) - 1 );
    end
end

value = T(n, n);




end

