def list_insert(L, x):
	x.next = L.nil.next
	L.nil.next = x
	#O(1)

def list_delete(L, x):
	N = L.nil
	while (N.next != x):
		N = N.next
	N.next = x.next
	#O(n)

def list_search(L, k):
	x = L.nil.next
	while (x != nil and x.key != k):
		x = x.next
	return x
	#O(n)
