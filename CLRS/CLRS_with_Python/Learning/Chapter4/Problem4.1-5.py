#Problem4.1-5
#15.7.16
#chuanlu

def max_subarray_j(A):
	flag = max(A)
	amin = 0
	amax = 0
	for i in range(len(A)):
		asum = 0
		for j in range(i, len(A)):
			asum += A[j]
			if asum >= flag:
				amin = i
				amax = j
				flag = asum		
	return(amin, amax, flag)

def max_subarray(A):
	key = A[0]
	for j in range(1, len(A) - 1):
		amin, amax, flag = max_subarray_j(A[:j])
		flag = max(key, flag)
		for i in range(j + 1):
			asum = sum(A[i : j + 1])
			if asum > flag:
				flag, amin, amax = asum, i, j
	amin2, amax2, flag2 = max_subarray_j(A[:len(A)]) #when j = len(A) - 1
	(flag, amax, amin) = map(max, [(flag, flag2), (amax, amax2), (amin, amin2)])
	return(amin, amax, flag)
		
A = [-1,4,6,-3,4,-3,125]
print(max_subarray(A))