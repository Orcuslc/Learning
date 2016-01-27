# fibonacci-heap
class element:
	'''
	basic element in the data structure
	'''
	def __init__(self, key, data = []):
		self.key = key
		self.data = data

class Node:
	'''
	basic node in the tree
	'''
	def __init__(self, elem):
		self.elem = elem
		self.left = self
		self.right = self
		self.p = None
		self.child = None
		self.degree = 0
		self.mark = False

class fib_heap:
	'''
	the class of fibonacci heap, nodes in which are type(Node)
	'''
	def __init__(self):
		self.min = Node(None)
		self.n = 0