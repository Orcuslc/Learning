#Exercise 7-1
#15.8.5

def hoare_partition(A, p, r):
	flag = A[p]
	i = p - 1
	j = r + 1
	while True:
		while True:
			j -= 1
			if A[j] <= flag:
				break
		while True:
			i += 1
			if A[i] >= flag:
				break
		if i < j:
			A[i], A[j] = A[j], A[i]
		else:
			return j

def quicksort(A, p, r):
	if p < r:
		q = hoare_partition(A, p, r)
		quicksort(A, p, q)
		quicksort(A, q+1, r)
	return A
	
A = [9,8,7,6,5,4,3,2,1]
p = 0
r = len(A) - 1
print(quicksort(A, p, r))