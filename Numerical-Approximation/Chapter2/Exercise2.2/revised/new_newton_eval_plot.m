function [] = new_newton_eval_plot(n)
    x_values = 2*pi/n * (0 :  n);
    f_values = sin(x_values);

    X = linspace(0, pi, 1e6);
    Y = linspace(0, pi, 1e6);
    
    args = newton_coefficient(x_values, f_values);

    Y = polynomail_eval(args, X, x_values);
%     for i = 1:length(Y)
%         Y(i) = new_newton_eval(args, X(i), x_values);
%     end;

    plot(X, Y);
    hold on;
    axis([0, pi, -1, 1]);
    plot(X, sin(X));

