#Binary Add
#15.7.29

def binary_add(A, B, n):
	flag = 0
	C = []
	for i in range(n):
		flag = flag + A[i] + B[i]
		if flag >= 2:
			C.append(flag % 2)
			flag = 1
		else:
			C.append(flag)
			flag = 0
	C.append(flag)		
	return C

A = [0,1,1,0,0,1,0,0]
B = [0,0,1,0,1,1,1,1]
print(binary_add(A, B, n = len(A)))
