function[u] = three_point_diff(a, b, c, N, u0, uN)
    format long;
    h = 1/N;
    A = -a/(h^2)*(diag(ones(N-2, 1), -1) + diag(ones(N-2, 1), 1) + diag(ones(N-1, 1)*-2, 0));
    B = b/(2*h)*(diag(ones(N-2, 1), -1) + diag(ones(N-2, 1), 1));
    C = c*eye(N-1);
    f = ones(N-1, 1);
    f(1) = f(1) + a/(h^2)*u0-b/(2*h)*u0;
    f(N-1) = f(N-1) + a/(h^2)*uN-b/(2*h)*uN;
    u = (A+B+C)\f;
    u = transpose(u);
