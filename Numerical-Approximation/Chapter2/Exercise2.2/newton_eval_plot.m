function [] = newton_eval_plot()
X = 0:0.01:pi;
% N= [200, 1000];
for i = 200
    figure(i);
    func = newton_eval(i);
    Y = subs(func, X);
    deviation = newton_deviation(X, Y);
    disp(deviation);
    plot(X, Y);
    hold on;
end;
    axis([0, pi, -1, 1]);
    plot(X, sin(X));

