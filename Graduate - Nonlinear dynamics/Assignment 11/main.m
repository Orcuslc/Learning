f1 = @(t, x, y, z) 10*(y-x);
f3 = @(t, x, y, z) -8/3*z+x*y;
t = [0, 120];
h = 0.004;
R = [1, 14, 24, 24.2, 28, 100, 102, 400];
for i = 1:length(R)
    r = R(i);
    figure(i);
    f2 = @(t, x, y, z) r*x-y-x*z;
    X0 = [-8, 8, r-1];
    res = RK43D(f1, f2, f3, X0, h, t);
    plot3(res(:,1), res(:,2), res(:, 3));
    grid on;
    xlabel('x');
    ylabel('y');
    zlabel('z');
    title(strcat('r = ', num2str(r)));
end