s = 10; b = 8/3; r = 28;
h = 0.004; t = [0, 120];

f1 = @(t, X) s*(X(2)-X(1));
f2 = @(t, X) r*X(1)-X(2)-X(1)*X(3);
f3 = @(t, X) -b*X(3)+X(1)*X(2);
f4 = @(t, X) -s*X(4)+s*X(5);
f5 = @(t, X) (r-X(3))*X(4)-X(5)-X(1)*X(6);
f6 = @(t, X) X(2)*X(4)+X(1)*X(5)-b*X(6);
f = {f1, f2, f3, f4, f5, f6};
X0 = [-8, 8, r-1, sqrt(2)/6, 5/6, 1/2];

res = RK4ND(f, X0, h, t);
tt = (t(1):h:t(2))';
val = res(:, 4:end);
v = log(sum(val.*val, 2))./tt;
plot(tt, v);
xlabel('t');
ylabel('val');