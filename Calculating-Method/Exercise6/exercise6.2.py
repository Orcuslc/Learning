#Exercise 6.2
#15.2.2
#author : chuanlu

import numpy as np
import pdb

#exercise6.2.2
def jacobi(A, b, x, tol):
	d = np.diag(A)
	d = [x ** -1 for x in d]
	D = np.diag(d)
	L = np.tril(A, -1)
	U = np.triu(A, 1)
	B = np.dot(D, L + U)
	g = np.dot(D, b)
	count = 0
	while True:
		new_x = np.dot(B, x) + g
		count += 1
		if c < tol:
			print(count)
			print(c)
			return new_x

def sor(A, b, x, omega, tol):
	d = np.diag(A)
	D = np.diag(d)
	L = np.tril(A, -1)
	U = np.triu(A, 1)
	T = np.linalg.inv(D - omega * L)
	B = np.dot(T, (1 - omega) * D + omega * U)
	g = omega * T
	count = 0
	while True:
		new_x = np.dot(B, x) + g
		count += 1
		c = np.linalg.norm((new_x - x), np.inf)
		x = new_x
		if c < tol:
			print(omega)
			print(count)
			print(c)
			return new_x

def cg(A, b, x, tol):
	r = b - np.dot(A, x)
	count = 0
	x = [x]
	r = [r]
	while True:
		count += 1
		if count == 1:
			p = r[0]
		else:
			beta = np.dot(np.transpose(r[-1]), r[-1]) / np.dot(np.transpose(r[-2]), r[-2])
			p = r[-1] + beta * p
		alpha = np.dot(np.transpose(r[-1]), r[-1]) / np.dot(np.dot(np.transpose(p), A), p)
		x_new = x + alpha * p
		r.append(r[-1] - alpha * np.dot(A, p))
		c = np.linalg.norm((x_new - x), np.inf)
		x = x_new
		if c < tol:
			print(count)
			print(c)
			return x_new


def main():
	N = 10
	h = 1/(N+1)
	f = lambda x, y: (x ** 2 + y ** 2) * np.exp(x * y)

	#exercise 6.2.1
	x = np.linspace(0, 1, N + 2)
	y = np.linspace(0, 1, N + 2)

	rank = N * N
	A = np.diag([4 for i in range(rank)]) + \
		np.diag([-1 for i in range(rank - 1)], -1) + \
		np.diag([-1 for i in range(rank - 1)], 1) + \
		np.diag([-1 for i in range(rank - N)], -N) + \
		np.diag([-1 for i in range(rank - N)], N)
	b = np.zeros(N * N)
	b = np.transpose(b)
	for i in range(N):
		for j in range(N):
			t = j + i * N
			b[t] = f(x[j + 1], y[i + 1]) * (h**2)
			if i == 0:
				b[t] += 1
			elif i == N - 1:
				b[t] += np.exp(x[j + 1]) 
			else:
				continue
			if j == 0:
				b[t] += 1
			elif j == N - 1:
				b[t] += np.exp(y[i + 1])
			else:
				continue
	print('exercise6.2.1')
	print(A)
	print(b)
	print('exercise6.2.2')
	print('jacobi')
	tol = 1e-5
	init = np.zeros(N*N).transpose() + 1
	result = jacobi(A, b, init, tol)
	print(result)
	print('SOR')
	omega_list = [1, 1.25, 1.5, 1.75]
	for omega in omega_list:
		result = sor(A, b, init, omega, tol)
		print(result)
	print('exercise6.2.3')
	print('CG')
	result = cg(A, b, init, tol)
	print(result)

if __name__ == '__main__':
	main()