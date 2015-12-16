#Heapsort
#15.7.20
#chuanlu
import math

def right(i):
	return 2*(i+1)

def left(i):
	return 2*i+1

def parent(i):
	return math.floor(i/2)

def heapsize(A):
	return len(A) - 1 #我们认为堆A的有效元素个数和数组A的长度相等

def max_heapify(A ,i, x):
	l = left(i)
	r = right(i)
	A_heapsize = x
	largest = 0
	if l < A_heapsize and A[l] > A[i]:
		largest = l
	else:
		largest = i
	if r < A_heapsize and A[r] > A[largest]:
			largest = r
	if largest != i:
		A[i], A[largest] = A[largest], A[i]
		max_heapify(A, largest, A_heapsize)
	return A

def min_heapify(A ,i, x):
	l = left(i)
	r = right(i)
	A_heapsize = x
	smallest = ''
	if l <= A_heapsize and A[l] > A[i]:
		smallest = l
	else:
		smallest = i
	if r <= A_heapsize and A[r] > A[smallest]:
		smallest = r
	if smallest != i:
		A[i], A[smallest] = A[smallest], A[i]
		max_heapify(A, smallest)
	return A

def build_max_heap(A, A_heapsize):
	for i in range(math.floor((len(A))/2), -1, -1):
		max_heapify(A, i, A_heapsize)
	return A

def heap_sort(A, A_heapsize):
	build_max_heap(A, A_heapsize)
	print(A)
	for i in range(len(A) - 1, 0, -1):
		A[0], A[i] = A[i], A[0]
		A_heapsize -= 1
		max_heapify(A, 0, A_heapsize)
	return A


#Priority Queue

def heap_extract_max(A, A_heapsize):
	if A_heapsize < 1:
		print('Error: Heap Underflow')
	A_max = A[0]
	A[0] = A[A_heapsize - 1]
	A_heapsize -= 1
	max_heapify(A, 0, A_heapsize)
	return A_max

def heap_maximum(A):
	return A[0]

def heap_increase_key(A, i, key):
	if key < A[i]:
		print('Error: No key is smaller than current key')
	A[i] = key
	while i > 0 and A[parent(i)] < A[i]:
		A[i], A[parent(i)] = A[parent(i)], A[i]
		i = parent(i)
	return A

def max_heap_insert(A, key, A_heapsize):
	A.append(float('-inf'))
	heap_increase_key(A, A_heapsize, key)
	return A

def heap_delete(A, i, A_heapsize):
	A.pop(i)
	A_heapsize -= 1
	max_heapify(A, i, A_heapsize)  #时间为O(lgn),如果使用build_max_heap则时间为O(nlgn)
	return A


A = [1,2,3,4,5,6,7,8,9]
A_heapsize = len(A) 
A = build_max_heap(A, A_heapsize)
#print(A)
#print(heap_sort(A, A_heapsize))
#print(heap_extract_max(A, A_heapsize))
#print(heap_increase_key(A, 2, 10))
#print(max_heap_insert(A, 12345, A_heapsize))
print(heap_delete(A, 5, A_heapsize))