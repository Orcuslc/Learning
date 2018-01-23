function y = u(x, t)
    p = x*exp(-t);
    y = exp(-2*(p-2).^2);