from numpy import exp, pi, log2

def recursive_dft(A):
	'''
	DFT of A using Recursive-FFT.
	In which A is an array, the length of which must be 2's power
	'''
	n = len(A)
	m = int(n/2)
	if n == 1:
		return A
	w_n = exp(1j * (2 * pi / n))
	w = 1
	A_0 = [A[2 * i] for i in range(0, m)]
	A_1 = [A[2 * i + 1] for i in range(0, m)]
	y_0 = recursive_dft(A_0)
	y_1 = recursive_dft(A_1)
	y = [0 for i in range(n)]
	for k in range(0, m):
		y[k] = y_0[k] + w * y_1[k]
		y[k + m] = y_0[k] - w * y_1[k]
		w = w * w_n
	return y

def recursive_idft(y):
	'''
	Inversed dft using Recursive-FFT
	In which y is an array, the length of which must be 2's power
	'''
	n = len(y)
	m = int(n/2)
	if n == 1:
		return y
	w_n = exp(-1j * 2 * pi / n)
	w = 1
	y_0 = [y[2 * i] for i in range(0, m)]
	y_1 = [y[2 * i + 1] for i in range(0, m)]
	a_0 = recursive_idft(y_0)
	a_1 = recursive_idft(y_1)
	a = [0 for i in range(n)]
	for k in range(0, m):
		a[k] = (a_0[k] + w * a_1[k]) / 2
		a[k + m] = (a_0[k] - w * a_1[k]) / 2
		w = w * w_n
	return a

def iterative_dft(a):
	'''
	DFT of A using iterative-FFT.
	In which A is an array, the length of which must be 2's power
	'''
	A = bit_reverse_copy(a)
	n = len(A)
	for s in range(1, int(log2(n)) + 1):
		m = 2 ** s
		w_m = exp(1j * 2 * pi / m)
		for k in range(0, n, m):
			w = 1
			for j in range(0, int(m/2)):
				t = w * A[k + j + int(m/2)]
				u = A[k + j]
				A[k + j] = u + t
				A[k + j + int(m/2)] = u - t
				w = w * w_m
	return A

def bit_reverse_copy(a):
	n = len(a)
	A = [0 for i in range(n)]
	for k in range(0, n):
		tmp = bin(k)[2:][::-1]
		while len(tmp) < int(log2(n)):
			tmp += '0'
		rev = int(tmp, 2)
		A[rev] = a[k]
	return A

def iterative_idft(y):
	'''
	Inversed dft using iterative-FFT
	In which y is an array, the length of which must be 2's power
	'''
	Y = bit_reverse_copy(y)
	n = len(Y)
	for s in range(1, int(log2(n)) + 1):
		m = 2 ** s
		w_m = exp(-1j * 2 * pi / m)
		for k in range(0, n, m):
			w = 1
			for j in range(0, int(m/2)):
				t = w * Y[k + j + int(m/2)]
				u = Y[k + j]
				Y[k + j] = u + t
				Y[k + j + int(m/2)] = u - t
				w = w * w_m
	return [y[i] / n for i in range(n)]

def main():
	A = [i for i in range(0, 8)]
	B = recursive_dft(A)
	C = recursive_idft(B)
	D = iterative_dft(A)
	E = [B[i] - D[i] for i in range(len(A))]
	F = iterative_idft(D)
	print(F)


if __name__ == '__main__':
	main()
