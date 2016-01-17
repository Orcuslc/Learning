# find_intersection
class event_queue:
	def __init__(self):
		self.data = []

	def insert(self, val):
		self.data.append(val)

	def pop(self):
		self.data.pop(0)

class node:
	def __init__(self):
		'''
		Attention: the key for a node is used for comparsion,
		while the data region contains the data of a node
		'''
		self.data = None
		self.key = None
		self.p = None
		self.left = None
		self.right = None
		self.height = 0		

class AVL_tree(node):
	def __init__(self):
		super().__init__()
		self.root = None

	def insert(self, x):




def find_intersection(S):
	'''
	input: a list of line segments with the format [[x1, y1], [x2, y2]]
	output: a list of intersection points among the segments in S, with for each 
			intersection point the segments that contain it, which means 
			that elements in it have the format [[x0, y0], [x1, y1], [x2, y2]],
			and in which x0, y0 form the intersection point
	'''
