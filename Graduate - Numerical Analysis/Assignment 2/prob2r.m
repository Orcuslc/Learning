function res = prob2(x);
%
    res = x./((x+1).^(2/3)+(x+1).^(1/3)+1);
    res = res';