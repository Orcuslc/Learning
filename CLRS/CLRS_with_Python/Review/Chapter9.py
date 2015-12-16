#Review of Chapter 9
#15.8.9
import random
def minimum(A):
	flag = A[0]
	for i in range(1, len(A)):
		if A[i] < flag:
			flag = A[i]
		return flag

def minimum_and_maxmium(A):
	if len(A) % 2 == 0:
		if A[0] < A[1]:
			flag1, flag2 = A[0], A[1]
		else:
			flag1, flag2 = A[1], A[0]
		key = 2
	else:
		flag1, flag2 = A[0], A[0]
		key = 1
	while key <= len(A) - 1:
		if A[key] < A[key+1]:
			small = A[key]
			big = A[key+1]
		else:
			small = A[key+1]
			big = A[key]
		if small < flag1:
			flag1 = small
		if big > flag2:
			flag2 = big
		key += 2
	return (flag1, flag2)

# A = [1,2,3,4,5,6,7]
# print(minimum_and_maxmium(A))

def randomized_select(A, p, r, i):
	if p == r:
		return A[p]
	q = ch.randomized_partition(A, p, r)
	k = q - p + 1
	if i == k:
		return A[q]
	elif i < k:
		return randomized_select(A, p, q-1, i)
	else:
		return randomized_select(A, q+1, r, i-k)

def new_partition(A, p, r, x):
	i = p - 1
	for j in range(p, r + 1):
		if A[j] <= x:
			i += 1
			A[i], A[j] = A[j], A[i]
	return i+1

def partition(A, p, r):
	flag = A[r]
	i = p - 1
	for j in range(p, r+1):
		if A[j] < flag:
			i += 1
			A[i], A[j] = A[j], A[i]
	A[i+1], A[r] = A[r], A[i+1]
	return i+1 

def insertion_sort(A):
	for i in range(1, len(A)):
		flag = A[i]
		j = i - 1
		while j >= 0 and A[j] > flag:
			A[j+1] = A[j]
			j -= 1
		A[j + 1] = flag
	return A


def select(A, p, r, i):
	if p == r:
		return A[p]
	q = partition(A, p, r)
	k = q - p + 1
	if i == k:
		return A[q]
	elif i < k:
		return select(A, p, q-1, i)
	else:
		return select(A, q+1, r, i-k)

def linear_timing_select(A, p, q, i):
	B = [A[5*i:5*i+5] for i in range((q-p+1)//5)]  #actually the number 5 can be replaced by any other even numbers larger than 3
	if (q-p+1) % 5 != 0:
		B.append(A[5*((q-p+1)//5):])	#NEED IT TO KILL THE POSSIB. OF AN EMPTY LIST
	C = [insertion_sort(B[i])[len(B[i])//2] for i in range(len(B))]
	flag = select(C, 0, len(C)-1, (len(A)//5 + 1)//2)
	k = new_partition(A, 0, len(A) - 1, flag)
	if i == k:
		return x
	elif i < k:
		return select(A, p, k, i)
	else:
		return select(A, k, q, i-k)

A = [random.randint(1,100) for i in range(100)]
print(A)
i = 28
print(linear_timing_select(A, 0, len(A)-1, i))
print(linear_timing_select.__doc__)