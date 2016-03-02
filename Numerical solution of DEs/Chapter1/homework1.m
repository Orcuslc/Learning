% homework1
% author: chuanlu
% 2016-03-02
format long
xx = 10 .^ [-1:-1:-16];
yy = (1 - cos(xx)) ./ (xx .^ 2);
semilogx(xx, yy);
    