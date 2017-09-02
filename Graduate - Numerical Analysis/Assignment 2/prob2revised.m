function res = prob2revised(x)
% prob 2;
% revised to x/(sqrt(x+1)+1);
    res = x./((x+1).^(1/2)+1);
    res = res';