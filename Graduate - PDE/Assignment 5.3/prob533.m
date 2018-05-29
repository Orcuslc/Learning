% bigf = @(x) .5*(x>=0).*(exp(-x)-1) + .5*(x<0).*(exp(x)-1);
% xx = -5:.01:5;
% for t = 0:1:10
%     plot(xx, bigf(xx-t)-bigf(xx+t)); hold on;
% end
% legend('t=0','t=1','t=5','t=10')

f = @(x) exp(-(x+5).^2);
g = @(x) -2*exp(-(x-5).^2);
xx = -10:.01:10;
for t = 1:.5:7
    plot(xx, f(xx-t)-g(xx+t)); hold on;
end