function res = gauss_legendre(f, n)
if n == 2
    x = [-0.5773502692, 0.5773502692];
    w = [1.0, 1.0];
elseif n == 3
    x = [-0.7745966692, 0, 0.7745966692];
    w = [5/9, 8/9, 5/9];
elseif n == 4
    x = [-0.8611363116, 0.8611363116, -0.3399810436, 0.3399810436];
    w = [0.3478546451, 0.3478546451, 0.6521451549, 0.6521451549];
elseif n == 5
    x = [-0.9061798459, 0.9061798459, -0.5384693101, 0.5384693101, 0];
    w = [0.2369268851, 0.2369268851, 0.4786286705, 0.4786286705, 0.5688888889];
elseif n == 6
    x = [-0.9324695142, 0.9324695142, -0.6612093865, 0.6612093865, -0.2386191861, 0.2386191861];
    w = [0.1713244924, 0.1713244924, 0.3607615730, 0.3607615730, 0.4679139346, 0.4679139346];
elseif n == 7
    x = [-0.9491079123, 0.9491079123, -0.7415311856, 0.7415311856, -0.4058451514, 0.4058451514, 0];
    w = [0.1294849662, 0.1294849662, 0.2797053915, 0.2797053915, 0.3818300505, 0.3818300505, 0.4179591837];
elseif n == 8
    x = [-0.9602898565, 0.9602898565, -0.7966664774, 0.7966664774, -0.5255324099, 0.5255324099, -0.1834346425, 0.1834346425];
    w = [0.1012285363, 0.1012285363, 0.2223810345, 0.2223810345, 0.3137066459, 0.3137066459, 0.3626837834, 0.3626837834];
end

res = sum(f(x).*w);