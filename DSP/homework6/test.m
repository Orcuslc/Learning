% Test
func = @(tlist)(cos(2*pi*0.2*tlist) + sin(2*pi*0.04*tlist));
[t, signal] = sampling([0, 200], 2048, func);
subplot(3, 1, 1), plot(t, signal), title('The signal'), xlabel('time'), ylabel('y');
[f1, p1] = power_spectrum(t, signal, 'p');
subplot(3, 1, 2), plot(f1, p1), title('Power spectrum with periodogram method'),...
    xlabel('Frequency'), ylabel('Power');
