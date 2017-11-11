f1 = @(x) exp(x);
g1 = @(x) (x+1)/2;
f2 = @(x) sin(x);
g2 = @(x) (x+1)*pi/4;
f3 = @(x) atan(x);
g3 = @(x) (x+1)/2;
f4 = @(x) log(x);
g4 = @(x) (x+3)/2;

xx = -1:1e-4:1;

%%%%%%%%%% (a) %%%%%%%%
figure(1);
error1 = zeros(8, 1);
for i = 1:8
    y1 = f1(g1(xx));
    y2 = near_minimax(f1, g1, i, xx);
    plot(g1(xx), abs(y1-y2));
    error1(i) = max(abs(y1-y2));
    hold on;
end
legend('n=1', 'n=2', 'n=3', 'n=4', 'n=5', 'n=6', 'n=7', 'n=8');
title('exp(x)');

%%%%%%%%% (b) %%%%%%%
figure(2);
error2 = zeros(8, 1);
for i = 1:8
    y1 = f2(g2(xx));
    y2 = near_minimax(f2, g2, i, xx);
    plot(g2(xx), abs(y1-y2));
    error2(i) = max(abs(y1-y2));
    hold on;
end
legend('n=1', 'n=2', 'n=3', 'n=4', 'n=5', 'n=6', 'n=7', 'n=8');
title('sin(x)');

%%%%%%%%% (c) %%%%%%
figure(3);
error3 = zeros(8, 1);
for i = 1:8
    y1 = f3(g3(xx));
    y2 = near_minimax(f3, g3, i, xx);
    plot(g2(xx), abs(y1-y2));
    error3(i) = max(abs(y1-y2));
    hold on;
end
legend('n=1', 'n=2', 'n=3', 'n=4', 'n=5', 'n=6', 'n=7', 'n=8');
title('atan(x)');

%%%%%%%% (d) %%%%%%%%%
figure(4);
error4 = zeros(8, 1);
for i = 1:8
    y1 = f4(g4(xx));
    y2 = near_minimax(f4, g4, i, xx);
    plot(g2(xx), abs(y1-y2));
    error4(i) = max(abs(y1-y2));
    hold on;
end
legend('n=1', 'n=2', 'n=3', 'n=4', 'n=5', 'n=6', 'n=7', 'n=8');
title('ln(x)');
