A = -1.e20;
n = 1000;
while n >= 0
    A = (1/(n+1) - A)/10;
    n = n - 1;
end;
disp(1)
