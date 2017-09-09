function res = largest_to_smallest(xx)
% Add an array from the largest number to the smallest number;
% `xx`: The input array, arranged from the largest to the smallest.
    res = single(0);
    for i = 1:length(xx)
        res = res + xx(i);
    end