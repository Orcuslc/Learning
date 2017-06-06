function [ value ] = romberg_iteration( func, inteval, tolerance )
% Iteration of romberg extrapolation

low = inteval(1);
high = inteval(2);

T = [ feval(func, low) + feval(func, high) ] / 2 * (high - low);
n = 1;
average = sum(T) / 2;

while 1
    n = n + 1;
    new_points = low + ( 2 * linspace( 1, 2 ^(n-1) , 2^(n-1) ) - 1 ) * (high - low) / (2 ^ n);
    sum_temp = sum( feval(func, new_points));
    average = (average * (2 ^ (n -1)) + sum_temp) / (2 ^ n) * (high-low);
    T( n, 1 ) = 0.5 * ( T( n-1, 1 ) + (high - low) / ( 2 ^ (n-1) ) * sum_temp );
    for i = 2 : n
        T( n, i ) = ( 4 ^ (i - 1) * T(n, i - 1) - T(n - 1, i - 1) ) / ( 4 ^ (i - 1) - 1 );
    end
%     if abs(( T(n, n) - T(n - 1, n - 1) ) / T(n-1, n-1)) < tolerance
    if abs((T(n, n) - T(n-1, n-1)) / average) < tolerance
        break
    end
    if n >= 20
        warning('n over 20, the iteration may not be convergence');
        break
    end
end

value = T(n, n);


end

