A = input('Enter the number A for which the square root is sought:  ');
Toll = input('Enter the desired tolerance:  ');
if A < 0
    error('A must be nonnegative.')
elseif Toll <= 0
    error('Tolerance must be positive.');
else
    x_old= -Toll;
    x_new=1;
    while abs((x_new-x_old)/x_new) > Toll
        x_old=x_new;
        x_new=(x_new+A/x_new)/2;
    end
    s1=sprintf('The square root of %8.6f is  %8.6f pm  %8.6f ',A,x_new,Toll);
    disp(s1);
end