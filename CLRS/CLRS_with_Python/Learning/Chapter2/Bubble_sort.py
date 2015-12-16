#Bubblesort
#15.7.16

def bubblesort(A):
	for i in range(len(A) - 1):
		for j in range(len(A) - 1, i, -1):
			if A[j] < A[j - 1]:
				A[j], A[j - 1] = A[j - 1], A[j]

	return A

A = [12,45,3,1,5,36]
print(bubblesort(A))
