function res = precise(xx)
% Add an array using double precision;
% `xx`: The input array, arranged from the largest to the smallest.
    res = sum(xx);
    res = single(res);