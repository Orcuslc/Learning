#Exercise 9-2
#15.8.11
import random

def partition_with_weighs(A, B, p, r):
	flag = A[r]
	i = p - 1
	for j in range(p, r):
		if A[j] < flag:
			i += 1
			A[j], A[i] = A[i], A[j]
			B[j], B[i] = B[i], B[j]
	A[i+1], A[r] = A[r], A[i+1]
	B[i+1], B[r] = B[r], B[i+1]
	return i+1

def quick_sort_with_weighs(A, B, p, r):
	if p < r:
		q = partition_with_weighs(A, B, p, r)
		quick_sort_with_weighs(A, B, p, q-1)
		quick_sort_with_weighs(A, B, q+1, r)
	return A, B

def find_medium_with_weighs(A, B):
	A, B = quick_sort_with_weighs(A, B, p = 0, r = len(A) - 1)
	flag = A[0]
	for i in range(1, len(A)):
		if flag < 0.5 and (flag + A[i]) >= 0.5:
			return A[i]
		flag += A[i]

# A = [0.1, 0.35, 0.05, 0.1, 0.15, 0.05, 0.2]
# B = [0.1, 0.35, 0.05, 0.1, 0.15, 0.05, 0.2]
# print(find_medium_with_weighs(A, B))

def select_with_weighs(A, B, p, r, w):
	if p == r:
		return A[p]
	q = partition_with_weighs(A, B, p, r)
	flag = 0
	for i in range(p, q+1):
		flag += B[i]
	if flag == w:
		return B[q]
	elif flag > w:
		return select_with_weighs(A, B, p, q-1, w)
	else:
		return select_with_weighs(A, B, q+1, r, w-flag)

