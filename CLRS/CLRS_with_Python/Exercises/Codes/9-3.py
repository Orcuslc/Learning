#Exercise 9-3
#15.8.11
'''
step1:
把数组分为两组，从中间分开，分别是A[1..n/2]和A[n/2+1..n]
step2:
依次比较A[1+k]和A[n/2+1+k]的大小，（0<=k<m/2），大的放右边，小的放左边
step3:
对小的一半进行Partition操作，比如step2中小的放左边，就Partition(A, 1, n/2, i)
与常规Partition不同的是，每当swap(A[i],A[j])时，同时进行swap(A[i+n/2], A[j+n/2])
step4:
Partition后的结果，A[1..i-1] <= A[i] < A[i+1..n/2]，第i小的元素在A[1..i]和A[n/2+1..n/2+1+i]这两个区间中
step5：
把A[1..i]和A[n/2+1..n/2+1+i]中的元素拿出来，放在另一个数组B中，那么数组B的元素个数是2i，递归地SELECT(B, i)，直到最终找到第i小的元素
'''
def partition_a_list(A):
	n = len(A) // 2
	for i in range(n):
		if A[i] >= A[n + i]:
			A[i], A[n + i] = A[n + i], A[i]
	return A

def partition_with_two_lists(A, B, p, r, i):
	A[i - 1], A[r] = A[r], A[i - 1]
	B[i - 1], B[r] = B[r], B[i - 1]
	flag = A[r]
	i = p - 1
	for j in range(r):
		if A[j] <= flag:
			i += 1
			A[i], A[j] = A[j], A[i]
			B[i], B[j] = B[j], B[i]
	A[i+1], A[r] = A[r], A[i+1]
	B[i+1], B[r] = B[r], B[i+1]
	return i+1

def little_key_select(A, i):
	n = len(A) // 2
	B = partition_a_list(A)[:n]
	C = partition_a_list(A)[n:]
	key = partition_with_two_lists(B, C, 0, n - 1, i)
	D = B[:key].extend(C[:key])
	return little_key_select(D, i)


