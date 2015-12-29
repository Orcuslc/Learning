function [ val ] = Bernstein_function(n, i, x)
val = nchoosek(n, i) .* (x .^ i) .* ((1-x) .^ (n-i));