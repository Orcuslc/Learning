#Quick Sort
#15.7.21
import random
def partition(A, p, r):
	x = A[r]
	i = p-1
	for j in range(p, r):
		if A[j] <= x:
			i += 1
			A[j], A[i] = A[i], A[j]
	A[i+1], A[r] = A[r], A[i+1]
	return i+1

def quicksort(A, p, r):
	if p < r:
		q = partition(A, p, r)
		quicksort(A, p, q-1)
		quicksort(A, q+1, r)
	return A

def randomized_partition(A, p, r):
	i = random.randint(p, r)
	A[r], A[i] = A[i], A[r]
	return partition(A, p, r)

def randomized_quicksort(A, p, r):
	if p < r:
		q = randomized_partition(A, p, r)
		randomized_quicksort(A, p, q-1)
		randomized_quicksort(A, q+1, r)

	return A
'''
A = [2,3,4,5,6,7,8,9,1]
print(randomized_quicksort(A, 0, len(A)-1))'''