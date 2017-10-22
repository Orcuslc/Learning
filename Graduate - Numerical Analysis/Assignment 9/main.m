f1 = @(x)(log(x));
p1 = @(x)(log(2)*x+0.5*(log(0.5*log(2))+1));
p2 = @(x)(0.3*x+(-29/30+4/3*log(2)));

x = 1:1e-2:2;
plot(x, abs(f1(x)-p1(x)), '*');
hold on;
plot(x, abs(f1(x)-p2(x)), '.');
legend('minimax', 'least square');
title('Error for minimax estimation and least square estimation');
xlabel('x');
ylabel('error');