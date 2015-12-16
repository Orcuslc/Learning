#Half Find
#15.7.29

'''
HALF-FIND(A, p, q, x):
	#We assume that A has been sorted
	r = floor((p+q)/2)
	if A[r] == x:
		return r
	else if A[r] > x:
		half-find(A, p, r-1, x)
	else:
		half-find(A, r+1, q, x)
'''
import math
def half_find(A, p, q, x):
	r = math.floor((p+q)/2)
	if A[r] == x:
		return(r)
	elif A[r] > x:
		half_find(A, p, r, x)
	else:
		print(r)
		half_find(A, r, q, x)

A = [1,2,3,4,5,6,7,8,9]
print(half_find(A, p = 0, q = len(A) - 1, x = 8))