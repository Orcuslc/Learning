import numpy as np

def count(A):
	MIN = float("inf")
	c = 0
	for i in range(len(A)):
		if A[i] < MIN:
			MIN = A[i]
			c += 1
	return c

def test(n, num_test):
	total = 0
	for i in range(num_test):
		A = np.arange(n)
		np.random.shuffle(A)
		total += count(A)
	return total/num_test

def harmonic(n):
	return sum([1/i for i in range(1, n+1)])

if __name__ == '__main__':
	n = 100
	print(harmonic(n))
	print(test(n, 10000000))