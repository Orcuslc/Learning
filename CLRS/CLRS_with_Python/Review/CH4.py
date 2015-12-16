#Chapter 4
#Review
#15.7.30
import math
def find_max_crossing_array(A, low, mid, high):
	leftflag = float('-inf')
	leftsum = 0
	max_left = mid
	for i in range(mid, low - 1, -1):
		leftsum += A[i]
		if leftsum >= leftflag:
			leftflag = leftsum
			max_left = i 
	rightflag = 0
	rightsum = 0
	max_right = mid
	for i in range(mid + 1, high + 1):
		rightsum += A[i]
		if rightsum >= rightflag:
			rightflag = rightsum
			max_right = i
	if leftsum + rightsum <0:
		return (-1,-1,0)
	else:
		return (max_left, max_right, leftsum + rightsum)
'''
def find_max_subarray(A, low, high):
	if low == high:
		return (low, high, A[low])
	else:
		mid = math.floor((low+high)/2)
		(left_low, left_high, left_sum) = find_max_subarray(A, low, mid)
		(right_low, right_high, right_sum) = find_max_subarray(A, mid + 1, high)
		(cross_low, cross_high, cross_sum) = find_max_crossing_array(A, low, mid, high)
		if left_sum >= right_sum and left_sum >= cross_sum:
			 return(left_low, left_high, left_sum)
		elif right_sum >= left_sum and right_sum >= cross_sum:
			return(right_low, right_high, right_sum)
		else:
			return(cross_low, cross_high, cross_sum)
'''

def find_max_subarray(A, low, high):
	#4.1-4
	if low == high:
		return (low, high, A[low])
	else:
		mid = math.floor((low+high)/2)
		(left_low, left_high, left_sum) = find_max_subarray(A, low, mid)
		(right_low, right_high, right_sum) = find_max_subarray(A, mid+1, high)
		(cross_low, cross_high, cross_sum) = find_max_crossing_array(A, low, mid, high)
		if left_sum >= right_sum and left_sum >= cross_sum:
			 return(left_low, left_high, left_sum)
		elif right_sum >= left_sum and right_sum >= cross_sum:
			return(right_low, right_high, right_sum)
		else:
			return(cross_low, cross_high, cross_sum)

A = [-1,-2,-3,-4,-5,-6]
print(find_max_subarray(A, 0, 5))


