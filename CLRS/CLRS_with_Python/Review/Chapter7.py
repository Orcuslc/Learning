#Chapter7
#15.8.15
import random

def partition(A, p, r):
	flag = A[r]
	i = p - 1
	for j in range(p, r):
		if A[j] < flag:
			i += 1
			A[i], A[j] = A[j], A[i]
	A[i+1], A[r] = A[r], A[i+1]
	return i+1

def quick_sort(A, p, r):
	if p < r:
		q = partition(A, p, r)
		quick_sort(A, p, q-1)
		quick_sort(A, q+1, r)

def randomized_partition(A, p, r):
	i = random.randint(p, r)
	A[r], A[i] = A[i], A[r]
	return partition(A, p, r)

def randomized_quicksort(A, p, r):
	if p < r:
		q = randomized_partition(A, p, r)
		randomized_quicksort(A, p, q)
		randomized_quicksort(A, q+1, r)

