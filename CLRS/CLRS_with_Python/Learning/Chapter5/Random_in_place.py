#Random in place
#15.7.19

import random

def Random_in_place(A):
	n = len(A)
	for i in range(0, n - 1):
		j = random.randint(i, n - 1)
		A[i], A[j] = A[j], A[i]
	return A

A = [1,2,3,4,5,6,7,8,9]
print(Random_in_place(A))
