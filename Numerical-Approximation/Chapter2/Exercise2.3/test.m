function  [ f ] = myHermiteipNev ( n , fn , x , varargin )
% Hermite interpolate (Neville method)
% input x , f(x) (f'(x), f''(x),.., if x is repeated), maybe y
% output f , or f(y) if y is provided
% 2015.09.27 Andy
if nargin < 2
    error ( 'Too few input arguments.' );
end
l = length ( n );
if l == 1
    error ( 'Too few nodes.' );
end
if l ~= length ( fn )
    error ( 'x and fx uncompatible.' );
end
for i = 1 : l
    for j = find ( n == n ( i ), 1 , 'first') : find ( n == n ( i ), 1 , 'last')
        if n ( j ) ~= n ( i )
            error ( 'Repeated nodes must be together.' );
        end
    end 
end 
if nargin == 2
    syms f x H tmp
end
for i = 1 : l
    H ( i , 1 ) = fn ( find ( n == n ( i ), 1 , 'first' ));
end
for j = 2 : l
    for i = 1 : l - j + 1
        if nargin == 2
            syms ac bd ;
        end
        x1 = find ( n == n ( i ), 1 , 'first' );
        x2 = find ( n == n ( i + j - 1 ), 1 , 'first' );
        if x1 == x2
            H ( i , j ) = fn ( x1 + j - 1 ) / factorial ( j - 1 );
        else
            H ( i , j ) = ( H ( i + 1 , j - 1 ) - H ( i , j - 1 ) )/( n ( i + j - 1 ) - n ( i ));
        end
    end
end
f = 0 ;
tmp = 1 ;
for i = 1 : l
    f = f + H ( 1 , i ) * tmp ;
    tmp = tmp * ( x - n ( i ));
end
disp ( 'Difference-quotient gram:' );
disp ( vpa ( H , 6 ));
if nargin == 2
    disp ( vpa ( simple ( f ), 6 ));
    f = vpa ( f , 6 );
end
end
