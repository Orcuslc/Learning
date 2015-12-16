#Max Subarray
#15.7.16

import math
#import sys

#sys.setrecursionlimit(10000)

def max_crossing_subarray(A, low, mid, high):
	left_sum = float('-inf')
	asum = 0
	max_left = 0
	max_right = 0
	for i in range(mid, low, -1):
		asum += A[i]
		if asum > left_sum:
			left_sum = asum
			max_left = i
	right_sum = float('-inf')
	asum = 0
	for i in range(mid + 1, high):
		asum += A[i]
		if asum > right_sum:
			right_sum = asum
			max_right = i
	return(max_left, max_right, left_sum + right_sum)

def max_subarray(A, low, high):
	if high == low:
		return(low, high, A[0])
	else:
		mid = math.floor((low + high) / 2)
		left_low, left_high, left_sum = max_subarray(A, low, mid)
		right_low, right_high, right_sum = max_subarray(A, mid + 1, high)
		cross_low, cross_high, cross_sum = max_crossing_subarray(A, low, mid, high)
		if left_sum >= right_sum and left_sum >= cross_sum:
			return(left_low, left_high, left_sum)
		elif right_sum >= left_sum and right_sum >= cross_sum:
			return(right_low, right_high, right_sum)
		else:
			return(cross_low, cross_high, cross_sum)

A = [-3,3,42,2,-1,43,-2,-234]
print(max_subarray(A, 0, len(A)))