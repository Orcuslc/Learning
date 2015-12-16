function[value] = newton_deviation(X, Y)
Z = sin(X);
flag = abs(Y(1) - Z(1));
for i = 1:length(Z)
    key = abs(Y(i) - Z(i));
%     disp(key); 
    if (key > flag)
        flag = key;
    end;
end;
value = vpa(flag, 6);

