f = @(x)(1 ./ (1 + 25 * (x .^ 2)));
plot_points = -1:1e-6:1;
yy = feval(f, plot_points);
plot(plot_points, yy);
hold on

for n = 4:4:12
    given_points = -1:1/n:1;
    function_values = feval(f, given_points);
    f_series = Newton_eval(given_points, function_values, plot_points);
    plot(plot_points, f_series);
    hold on
end
axis([-1, 1, -1, 1]);
legend('f(x)', 'n = 4', 'n = 8', 'n = 12', 'Location', 'best');