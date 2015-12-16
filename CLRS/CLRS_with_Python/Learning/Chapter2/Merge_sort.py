#Merge Sort
#15.7.16

def merge_sort(A, p, q, r):
	x = q - p + 1
	y = r - q
	L = []
	R = []
	for i in range(x):
		L.append(A[p + i - 1])
	for i in range(y):
		R.append(A[q + i])
	L.append(float('inf'))
	R.append(float('inf'))
	i = j = 1
	for k in range(p, r):
		if L[i] <= R[j]:
			A[k] = L[i]
			i += 1
		else:
			A[k] = R[j]
			j += 1
	return A
A = [23,6,3,867,3,7,9576,324,26,654,23,4,457,76]
p = 1
q = 4
r = 10
print(merge_sort(A, p, q, r))