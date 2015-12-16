#Problem 4.1-2
#15.7.16
#chuanlu

def max_subarray(A):
	flag = max(A)
	amin = 0
	amax = 0
	for i in range(len(A)):
		asum = 0
		for j in range(i, len(A)):
			asum += A[j]
			if asum >= flag:
				amin, amax, flag = i, j, asum
				
	return(amin, amax, flag)

A = [-1,4,6,-3,4,-34,2,-5,56,1,-2,4]
print(max_subarray(A))