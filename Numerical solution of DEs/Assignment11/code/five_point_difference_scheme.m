function u = five_point_difference_scheme(f, N)
    h = 1/N;
    n = N-1;
    I = eye(n, n);