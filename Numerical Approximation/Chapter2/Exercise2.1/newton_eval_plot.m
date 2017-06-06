function [value] = newton_eval_plot()
X = -1:0.01:1;
for i = 1:20
    func = newton_eval(i);
    Y = subs(func, X);
    plot(X, Y);
    hold on;
    axis([-1, 1, -1, 1]);
end;
