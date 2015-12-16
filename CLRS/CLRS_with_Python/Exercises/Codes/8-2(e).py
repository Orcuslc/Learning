#Exercise 8-2(e)
#15.8.8

def stable_quicksort(A, k):
	B = []
	for i in range(1, k+2):
		B.append(0)
	for x in A:
		B[x] += 1
	print(B)
	flag = 0
	while flag <= len(A):
		for j in range(1, len(B)):
			for i in range(B[j]):
				A[flag + i] = j
				flag += 1
				print(A)
	return A

def posit_sort(A, k):
	B = []
	for i in range(k+1):
		B.append(0)
	for i in range(len(A)):
		B[A[i]] += 1
	for i in range(len(B)):
		B[i] = B[i] + B[i-1]
	for i in range(k, 0, -1):
		A[B[i]-1] = i
		B[i] = B[i] - 1
	return A

A = [1,2,3,3,2,3,3,3,2,1,1,1,1,1,1,2]
print(posit_sort(A, k = 3))
