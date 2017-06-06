function[ value ] = experiment1( x )
value(x==0) = 0;
value(x~=0) = 1./sqrt(x(x~=0));