#2-3(b)

def power(x, n):
	y = 1
	for i in range(n):
		y = power(x, n-1) * x
	return y

def polygen(A, x):
	s = 0
	for i in range(len(A)):
		s += A[i] * power(x, i)
	return s

A = [1,1,1,1,1,1]
x = 2
print(polygen(A, x))