function [args] = hermite_coefficient(x_values, f_values)
n = length(x_values);
for i = 1 : n
    f_values_iter(i , 1) = f_values(find(x_values == x_values( i ), 1 , 'first'));
end;
for j = 2 : n 
    for i = 1 : n - j + 1
        pos1 = find (x_values == x_values(i), 1 , 'first');
        pos2 = find (x_values== x_values(i + j - 1), 1 , 'first');
        if pos1 == pos2
            f_values_iter(i , j) = f_values(pos1 + j - 1) / factorial(j - 1);
        else
            f_values_iter(i , j) = (f_values_iter(i + 1 , j - 1) - f_values_iter(i , j - 1))/(x_values(i + j - 1) - x_values(i));
        end
    end
end
args = f_values_iter(1,:);

