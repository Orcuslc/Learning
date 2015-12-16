format long
% func1 = @(x)( sin(x) );
% inteval1 = [0, pi];
% func2 = @(x)( exp(x) );
% inteval2 = [0, 1];

func2 = @(x)( 1 ./ ( 1 + 25 .* (x .* x)));
inteval2 = [-1, 1];
exact_int2 = atan(5) - atan(-5);

func1 = @(x)(abs(x));
inteval1 = [-1, 1];
exact_int1 = 1;

n = 8;
% exact_int1 = 2;
% exact_int2 = exp(1) - 1;

residue1 = zeros( 1, n + 1 );
residue2 = zeros( 1, n + 1 );

for i = 0 : n
    residue1( i+1 ) = abs( exact_int1 - newton_cotes( func1, inteval1, i ));
    residue2( i+1 ) = abs( exact_int2 - newton_cotes( func2, inteval2, i ));
end
disp(residue1);
disp(residue2);

figure(1)
semilogy( linspace( 0, n, n +1 ), residue1, '*-' );
hold on;
grid on;
semilogy( linspace( 0, n, n + 1 ), residue2, '*-' );
legend( 'abs(x) in [-1, 1]','1/(1 + 25x^2) in [-1, 1]', 'location', 'best');
% legend( 'sin(x) in [0, pi]', 'exp(x) in [0, 1]', 'location', 'best' );
% title( {'Residue of integration of sin(X) in [0, pi] and exp(x) in [0, 1],';' using Newton-Cotes Format'} );
title( {'Residue of integration of abs(X) in [-1, 1] and (1/(1+25x^2)) in [-1, 1],';' using Newton-Cotes Format'} );
