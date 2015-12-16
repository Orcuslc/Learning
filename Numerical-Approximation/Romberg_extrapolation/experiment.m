%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                              exp1                                  %       
%%%%%%%%%%%%%%%%%%%%%%%%%%%

inteval1 = [0, 1];
exact_value1 = 2;
result1 = romberg_extrapolation(@experiment1, [0, 1]);
residue1 = abs(exact_value1 - result1);
disp(residue1);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                               exp2                                   %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inteval2 = [-1, 1];
f2 =@(x)(abs(x));
exact_value2 = 1;
result2 = romberg_extrapolation(f2, inteval2);
residue2 = abs(exact_value2 - result2);
disp(residue2);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                              exp3                                    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%

inteval3 = [0, pi];
f3 = @(x)(sin(100 .* x));
exact_value3 = 0;
result3 = romberg_extrapolation(f3, inteval3);
residue3 = abs(exact_value3 - result3);
disp(residue3)