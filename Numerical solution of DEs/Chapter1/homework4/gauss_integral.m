function [ value ] = gauss_integral( func, order )
%GAUSS_INTEGRAL Calculate the intergral of func in [0, 1] with
%Gauss-Legendre Formula.
if order == 1
    value = feval(func, 0.5);
    return
end
[point, weight] = gauss_coefficient_legendre(order - 1);
transfered_point = point * 0.5 + 0.5;
value = weight * feval(func, transfered_point) * 0.5;

end

