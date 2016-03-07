% homework2.m
% author: chuanlu
% 2016-03-02

op1 = 'A1';
op2 = 'A2';
N = 100;
cond1 = zeros(1, N);
cond2 = zeros(1, N);
for n = 1 : N
    A1 = make_matrix(op1, n);
    A2 = make_matrix(op2, n);
    cond1(n) = cond(A1);
    cond2(n) = cond(A2);
end
n = [1:N];
figure(1);
semilogy(n, cond1, '*-');
figure(2);
plot(n, cond2, '*-');
%     disp('cond1:');
%     disp(cond1);
%     disp('cond2:');
%     disp(cond2);