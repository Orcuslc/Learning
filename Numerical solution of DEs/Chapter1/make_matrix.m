% make matrix
% author: chuanlu
% 2016-03-02
function [A] = make_matrix(op, n)
    if nargin < 1
        error('More args needed --make matrix');
    elseif nargin == 1
        op = 'A1';
    end
    
    if op == 'A1'
        c1 = zeros(1, n - 1);
        c1(2 : n - 1) = -3;
        c2 = zeros(1, n - 2) + 2;
        A = eye(n) + diag(c1, -1) + diag(c2, -2);
    elseif op == 'A2'
        c1 = zeros(1, n - 1);
        c1(2 : n - 1) = -3;
        c2 = zeros(1, n - 2) + 2;
        A = eye(n) + diag(c1, -1) + diag(c2, -2);
        A(1, n) = -1;
    else
        error('Operation Failed to Match A1 or A2');
    end