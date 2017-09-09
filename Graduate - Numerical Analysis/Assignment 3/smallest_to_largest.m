function res = smallest_to_largest(xx)
% Add an array from the smallest number to the largest number;
% `xx`: The input array, arranged from the largest to the smallest.
    res = single(0);
    for i = length(xx):-1:1
        res = res + xx(i);
    end
