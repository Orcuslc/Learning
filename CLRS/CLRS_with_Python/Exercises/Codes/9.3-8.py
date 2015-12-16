#Exercise9.3-8
#15.8.11

def find_medium_of_two_lists(A, B, low, high):
	n = len(A)
	while low <= high:
		middle = (low+high)//2
		if middle == n-1 and A[middle] <= B[0]:
			return A[middle]
		if B[n - middle - 2] <= A[middle] <= B[n - middle - 1]:
			return A[middle]
		elif B[n - middle - 1] <= A[middle]:
			high = middle - 1
		else:
			low = middle + 1

A = [1,2,3,4,5]
B = [1,3,5,7,9]
print(find_medium_of_two_lists(A, B, low = 0, high = 4))