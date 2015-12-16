function [value] = lagrange_eval(x)
    sum = 0;
    fi = [1,3,1/3];
    xi = [0,1,-1];
    for i = 1:length(fi)
        local_sum = 1;
        for j = 1:length(fi)
            if j ~= i
                local_sum = local_sum * (x - xi(j))/(xi(i) - xi(j));
            end;
        end;
        sum = sum + local_sum * fi(i);
    end;
    value = sum;