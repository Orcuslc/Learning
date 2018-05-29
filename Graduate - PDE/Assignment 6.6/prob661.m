ref = [pi, 0, 0, 0];
imf = [0, 1, 1/2, 1/3];

D = 8;
N = 2.^(2:(D+1));
ReRes = zeros(6, 4);
ImRes = zeros(6, 4);

for i = 1:D
    [d0, d] = fast(N(i));
    ReRes(i, 1) = abs(ref(1) - real(d0));
    ImRes(i, 1) = abs(imf(1) - imag(d0));
    ReRes(i, 2:4) = abs(ref(2:4) - real(d(1:3)));
    ImRes(i, 2:4) = abs(imf(2:4) - imag(d(1:3)));
end

for i = 1:4
    figure(i);
    subplot(211);
    loglog(N, ReRes(:, i));
    title('Real part abs err');
    subplot(212);
    loglog(N, ImRes(:, i));
    title('Imag part abs err');
end