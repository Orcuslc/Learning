# Descrete Fourier Transformation
# Using Radix-2 FFT

import numpy as np
import time
from matplotlib import pyplot as plt

pi = np.pi
exp = np.exp


def timeit(func):
	def wrapper(*args, **kw):
		time1 = time.time()
		result = func(*args, **kw)
		time2 = time.time()
		print(func.__name__, time2-time1)
		return result
	return wrapper

def get_w(n):
	return [0, 0]+[exp(-1j*2*pi/(2**k)) for k in range(1, n)]

@timeit
def bit_reverse(x, n):
	r = bin(x)
	l = n - len(r) + 2
	return int(('0'*l+r[2:])[::-1], 2)

# def dft(A):
# 	n = len(A)
# 	w = get_w(int(np.log2(n)))
# 	def _iter(A, n):
# 		if n == 2:
# 			return [A[0]+A[1], A[0]-A[1]]
# 		else:
# 			half = int(n/2)
# 			wn = w[int(np.log2(n))]
# 			A1 = _iter(A[:half], half)
# 			A2 = _iter(A[half:], half)
# 			return [A1[i]+wn*A2[i] for i in range(half)] + [A1[i]-wn*A2[i] for i in range(half)]
# 	return _iter(A, n)

def dft_slow(x):
    """Compute the discrete Fourier Transform of the 1D array x"""
    x = np.asarray(x, dtype=float)
    N = x.shape[0]
    n = np.arange(N)
    k = n.reshape((N, 1))
    M = np.exp(-2j * np.pi * k * n / N)
    return np.dot(M, x)

@timeit
def dft(x):
    x = np.asarray(x, dtype=float)
    N = x.shape[0]

    if N % 2 > 0:
        raise ValueError("size of x must be a power of 2")
    elif N <= 32:  
        return dft_slow(x)
    else:
        X1 = dft(x[::2])
        X2 = dft(x[1::2])
        w = exp(-2j * pi * np.arange(N) / N)
        return np.concatenate([X1 + w[:N / 2] * X2, X1 + w[N / 2:] * X2])

if __name__ == '__main__':
	n = 2**10
	x = [2*pi*i/n for i in range(n)]
	A = [np.sin(2*pi*i/n) for i in range(n)]
	b = dft(A)
	c = np.fft.fft(A)
	b1 = np.fft.ifft(b)
	c2 = np.fft.ifft(c)
	plt.figure(1)
	plt.plot(x, b1)
	plt.figure(2)
	plt.plot(x, c2)
	plt.show()