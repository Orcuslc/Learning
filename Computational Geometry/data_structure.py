# useful data structures 

'''
AVL Tree
'''
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
		if self.root == None:
			self.root = x
		else:
			self._put(x, self.root)

	def _put(self, x, node):
		if node == None:
			node = x
		elif x.key < node.key:
			self._put(x, node.left)
			if self.get_height(node.left) - self.get_height(node.right) == 2:
				if x.key < node.left.key:
					self.left_rotate(node)
				else:
					self.double_left_rotate(node)
		elif x.key > node.key:
			self._put(x, node.right)
			if self.get_height(node.right) - self.get_height(node.left) == 2:
				if x.key < node.right.key:
					self.double_right_rotate(node)
				else:
					self.right_rotate(node)
		node.height = max(self.get_height(node.right), self.get_height(node.left)) + 1

	def search(self, x):
		if self.root == None:
			return None
		else:
			return self._find(x, self.root)

	def _find(self, x, node):
		if node == None:
			return None
		elif x.key < node.key:
			return self._find(x, node.left)
		elif x.key > node.key:
			return self._find(x, node.right)
		else:
			return node

	def _getmin(self, node):
		if self.root == None:
			return None
		elif 
	

	def delete(self, x):
		self._remove(x, self.root)

	def _remove(self, x, node):
		if node == None:
			raise KeyError, 'Key Not In AVL Tree'
		elif x.key < node.key:
			self._remove(x, node.left)
			if self.get_height(node.right) - self.get_height(node.left) == 2:
				if self.get_height(node.right.right) >= self.get_height(node.right.left):
					self.right_rotate(node)
				else:
					self.double_right_rotate(node)
			node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
		elif x.key > node.key:
			self._remove(x, node.right)
			if self.get_height(node.left) - self.get_height(node.right) == 2:
				if self.get_height(node.left.left) >= self.get_height(node.left.right):
					self.left_rotate(node)
				else:
					self.double_left_rotate(node)
			node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
		elif node.left and node.right:
			if self.get_height(node.left) < self.get_height(node.right):
				min_node = self._getmin(node.right)
				node.data = min_node.data
				node.key = min_node.key
				node.right = self._remove(node, node.right)
			else:
				max_node = self._getmax(node.left)
				node.data = max_node.data
				node.key = max_node.key
				node.left = self._remove(node, node.left)
			node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1
		else:
			if node.right:
				node = node.right
			else:
				node = node.left
		return node

	def left_rotate(self, x):
		y = x.left
		x.left = y.right
		y.right = x
		x.height = max(get_height(x.left), get_height(x.right)) + 1
		y.height = max(get_height(y.left), get_height(x)) + 1

	def right_rotate(self, x):
		y = x.right 
		x.right = y.left
		y.left = x
		x.height = max(get_height(x.left), get_height(x.right)) + 1
		y.height = max(get_height(y.right), get_height(x)) + 1

	def double_left_rotate(self, x):
		self.right_rotate(x.left)
		self.left_rotate(x)

	def double_right_rotate(self, x):
		self.left_rotate(x.right)
		self.right_rotate(x)

	def traversal(self, x):
		pass

	def get_height(self, x):
		if x == None:
			return -1
		else:
			return x.height




