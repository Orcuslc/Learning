a = 1;
b = -1;
k = 1;
x = -5:.01:5;
for t = [.01, .1, .5, 2]
    u = 1/2*(b+a+b*erf(x/sqrt(4*k*t))-a*erf(x/sqrt(4*k*t)));
    plot(x, u);
    hold on;
end