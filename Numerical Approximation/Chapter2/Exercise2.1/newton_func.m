function [value] = newton_func(args, x_values)
    syms x;
    value = args(1);
    for i = 2: length(args)
        temp = 1;
        for j = 1:i-1
            temp =temp *(x - x_values(j));
        end
        value = value + args(i) * temp;
    end;
        
        
        
            
            