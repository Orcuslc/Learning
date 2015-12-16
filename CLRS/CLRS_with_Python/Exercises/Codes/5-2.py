#5-2
#15.8.3
import random
def random_search(A, x):
	key = []
	while len(key) < len(A):
		index = random.randint(0, len(A)-1)
		if A[index] == x:
			return index
		else:
			if index not in key:
				key.append(index)
			continue
	return 'NULL'

A = [1,2,3,4,5,6,7,8,9]
x = 10
print(random_search(A, x))

def determined_search(A, x):
	for index in range(len(A)):
		if A[index] == x:
			return index
	return 'NULL'

def scramble_search(A, x):
	n = len(A)
	for i in range(n):
		j = random.randint(i, n-1)
		A[i], A[j] = A[j], A[i]
	return determined_search(A, x)


