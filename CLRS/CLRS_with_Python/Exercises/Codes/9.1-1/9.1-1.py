#Exercise 9.1-1
#15.8.9

class Node(object):
	def __init__(self, data, left, right, nextnode):
		self.data = data
		self.left = left
		self.right = right
		self.next = nextnode

def create_tree(A):
	head = Node(None, None, None, None)
	for i in range(len(A)):
		N = Node(A[i])
		N.next = head
		head = N
	return head

# def find_second_minimal(A):
A = [1,2,3,4]
print(create_tree(A))