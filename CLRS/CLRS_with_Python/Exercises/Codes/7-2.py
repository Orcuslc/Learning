#Exercise 7-2
#15.8.5
import random
#以下这种方法事实上是有问题的，它仅对A[r]多次重复时有效（但是题目要求的好像就是如此）
def new_partition(A, p, r):
	flag = A[r]
	i = p - 1
	k = p - 1
	for j in range(p, r):
		if A[j] < flag:
			i += 1
			k += 1
			A[i], A[j], A[k] = A[j], A[k], A[i]
		elif A[j] == flag:
			k += 1
			A[k], A[j] = A[j], A[k]
	A[k+1], A[r] = A[r], A[k+1]
	return i+1, k+1

def new_randomized_partition(A, p, r):
	i = random.randint(p, r)
	A[r], A[i] = A[i], A[r]
	return new_partition(A, p, r)

def new_randomized_quicksort(A, p, r):
	if p < r:
		q, t = new_randomized_partition(A, p, r)
		new_randomized_quicksort(A, p, q - 1)
		new_randomized_quicksort(A, t + 1, r)
	return A

A = [3,4,5,6,7,7,7,7,1,2,3,4,6,7,1,2,3]
print(new_randomized_quicksort(A, p = 0, r = len(A) -1))
#print(new_partition(A, p = 0, r = len(A) - 1))