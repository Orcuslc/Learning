#linear_search
#15.7.15

def linear_search(A, key):
	for index in range(len(A)):
		if A[index] == key:
			return index
	return 'NIL'

A = [1, 2,43,57,476,32]
print(linear_search(A, 42))

