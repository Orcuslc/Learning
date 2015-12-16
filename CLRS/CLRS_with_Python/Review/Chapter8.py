#Review on Chapter 8
#15.8.7

def counting_sort(A, k):
	C = []
	B = []
	for i in range(k):
		B.append(0)
	for x in range(k):
		C.append(0)
	for i in range(len(A)):
		C[A[i]] += 1
	for i in range(1, k):
		C[i] = C[i] + C[i-1]
	# print(C)
	for j in range(len(A)-1, -1, -1):
		B[C[A[j]]] = A[j]
		C[A[j]] -= 1
	return B

A = [9,8,7,6,5,4,3,2,1]
print(counting_sort(A, k = max(A) + 1))

# def bucket_sort(A):
# 	n = len(A)
# 	B = []
# 	for x in range(n):
# 		B.append(0)
# 	for i in range(n):
		



