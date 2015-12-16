#Exercising Chapter2
#15.7.30
import math
def insertion_sort(A):
	for index in range(1, len(A)):
		flag = A[index]
	i = index - 1
	while i > 0 and A[i] > flag:
		A[i + 1] = A[i]
		i -= 1
	A[i + 1] = flag
	return A

def merge(A, p, q, r):
	k = q - p + 1
	l = r - q
	L = []
	R = []
	for i in range(k):
		L.append(A[p + i])
	for j in range(l):
		R.append(A[q + i + 1])
	L.append(inf('float'))
	R.append(inf('float'))
	i = 0
	j = 0
	for t in range(p, q+1):
		if L[i] <= R[j]:
			A[t] = L[i]
			i += 1
		else:
			A[t] = R[j]
			j += 1
	return A

def merge_sort(A, p, r):
	if p < r:
		q = math.floor((p+r)/2)
		merge_sort(A, p, q)
		merge_sort(A, q+1, r)
		merge(A, p, q, r)
	return A

def bubble_sort(A):
	for i in range(len(A)):
		for j in range(len(A) - 1, i, -1):
			if A[j] < A[j-1]:
				A[j], A[j-1] = A[j-1], A[j]
	return A

