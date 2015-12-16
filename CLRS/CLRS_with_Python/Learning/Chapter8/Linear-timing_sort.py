#Linear-timing Sort
#15.7.24

def counting_sort(A, k):
	#We assume elements in array A are not less than 0
	C = []
	B = []
	for i in range(k):
		C.append(0)
	for i in range(len(A)):
		B.append(0)
	for j in range(len(A)):
		C[A[j]] += 1
		#now C[i] contains the number of elements equal to i
	for i in range(1, k):
		C[i] += C[i - 1]
		#now C[i] contains the number of elements less than or equal to i
	for j in range(len(A)-1, -1, -1):
		B[C[A[j]] - 1] = A[j]
		C[A[j]] -= 1
	print(B)

def radix_sort(A, d):
	

A = [3,4,1,4,2,6,8,1,4,0,2]
counting_sort(A, k = max(A) + 1)