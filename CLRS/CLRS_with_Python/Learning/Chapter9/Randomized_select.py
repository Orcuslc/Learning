#Randomized Select
#15.7.25
from Quick_sort import randomized_partition

def randomized_select(A, p, r, i):
	if p == r:
		return A[p]
	q = randomized_partition(A, p, r)
	k = q - p + 1
	if i == k:
		return A[q]
	elif i < k:
		return randomized_select(A, p, q-1, i)
	else:
		return randomized_select(A, q+1, r, i-k)

A = [2,3,4,5,7,8,32,2,1,324,1,1,2,2,1]
print(randomized_select(A, 0, len(A) - 1, 10))