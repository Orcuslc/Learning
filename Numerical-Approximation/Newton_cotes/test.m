func = @(x)(exp(x));
inteval = [0, 1];
order = 4;
n = newton_cotes( func, inteval, order );
disp(n);