#Exercise 7-6
#15.8.7
import random
def cmp(A, B, i, j):
	if B[j] < A[i]:
		return 1  #区间i大于区间j
	elif B[i] < A[j]:
		return -1 #区间i小于区间j
	else:
		return 0 #区间i与区间B有重叠，认为两者相等

def interval_partiton(A, B, p, r):
	i = p - 1
	key = random.randint(p, r)
	A[key], A[r] = A[r], A[key]
	for j in range(p, r):
		# print(i, j, cmp(A, B, j, r)) 
		if cmp(A, B, j, r) != 1:
			i += 1
			A[i], A[j] = A[j], A[i]
			B[i], B[j] = B[j], B[i]
			# print(A[i], B[i], A[j], B[j])
	# print(i, j)
	A[i+1], A[r] = A[r], A[i+1]
	B[i+1], B[r] = B[r], B[i+1]
	# print(A, B)
	return i + 1
A = [1,3,5,9,7,6,8]
B = [2,4,6,8,10,9,12]
print(interval_partiton(A, B, 0, len(A)-1))

# 当所有区域都相等时，只要按照7.2-c即可