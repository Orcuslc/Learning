# useful data structures 

'''
AVL Tree
'''
class Node:
	'''
	Attention: the key for a node is used for comparsion,
	while the data region contains the data of a node.
	'''
	def __init__(self, key, data):
		self.key = key
		self.data = data
		self.left = None
		self.right = None
		self.p = None
		self.height = 0


class AVLTree(Node):
	'''
	Nodes are sorted by keys, and non-leaf nodes contains data as well.
	'''
	def __init__(self):
		self.root = None

	def find(self, x):
		if self.root is None:
			return None
		else:
			return self._find(x, self.root)

	def _find(self, x, node):
		if node is None:
			return None
		elif x.key < node.key:
			return self._find(x, self.left)
		elif x.key > node.key:
			return self._find(x, self.right)
		else:
			return node

	def findMin(self):
		if self.root is None:
			return None
		else:
			return self._findMin(self.root)

	def _findMin(self, node):
		if node.left:
			return self._findMin(node.left)
		else:
			return node

	def findMax(self):
		if self.root is None:
			return None
		else:
			return self._findMax(self.root)

	def _findMax(self, node):
		if node.right:
			return self._findMax(node.right)
		else:
			return node

	def height(self,node):
		if node is None:
			return -1
		else:
			return node.height
    
	def singleLeftRotate(self, node):
		k1 = node.left
		node.left = k1.right
		k1.right = node
		node.height = max(self.height(node.right), self.height(node.left)) + 1
		k1.height = max(self.height(k1.left), node.height) + 1
		return k1

	def singleRightRotate(self, node):
		k1 = node.right
		node.right = k1.left
		k1.left = node
		node.height = max(self.height(node.right), self.height(node.left)) + 1
		k1.height = max(self.height(k1.right), node.height) + 1
		return k1

	def doubleLeftRotate(self, node):
		node.left = self.singleRightRotate(node.left)
		return self.singleLeftRotate(node)

	def doubleRightRotate(self, node):
		node.right = self.singleLeftRotate(node.right)
		return self.singleRightRotate(node)

	def put(self, node):
		if not self.root:
			self.root = node
		else:
			self.root = self._put(node, self.root)

	def _put(self, x, node):
		if node is None:
			node = x
		elif x.key < node.key:
			node.left = self._put(x, node.left)
			if (self.height(node.left) - self.height(node.right)) == 2:
				if x.key < node.left.key:
					node = self.singleLeftRotate(node)
				else:
					node = self.doubleLeftRotate(node)           
		elif x.key > node.key:
			node.right = self._put(x, node.right)
			if (self.height(node.right) - self.height(node.left)) == 2:
				if x.key < node.right.key:
					node = self.doubleRightRotate(node)
				else:
					node = self.singleRightRotate(node)
		node.height = max(self.height(node.right), self.height(node.left)) + 1
		return node
        
	def delete(self, node):
		self.root = self.remove(node, self.root)

	def remove(self, x, node):
		if node is None:
			raise (KeyError,'Error,key not in tree')
		elif x.key < node.key:
			node.left = self.remove(x, node.left)
			if (self.height(node.right) - self.height(node.left)) == 2:
				if self.height(node.right.right) >= self.height(node.right.left):
					node = self.singleRightRotate(node)
				else:
					node = self.doubleRightRotate(node)
				node.height = max(self.height(node.left), self.height(node.right)) + 1   
		elif x.key > node.key:
			node.right=self.remove(x, node.right)
			if (self.height(node.left) - self.height(node.right)) == 2:
				if self.height(node.left.left) >= self.height(node.left.right):
					node = self.singleLeftRotate(node)
				else:
					node = self.doubleLeftRotate(node)
			node.height = max(self.height(node.left), self.height(node.right)) + 1        
		elif node.left and node.right:
			if node.left.height <= node.right.height:
				minNode = self._findMin(node.right)
				node.key = minNode.key
				node.data = minNode.data
				node.right = self.remove(node, node.right)
			else:
				maxNode = self._findMax(node.left)
				node.key = maxNode.key
				node.data = maxNode.data
				node.left = self.remove(node, node.left)
			node.height = max(self.height(node.left), self.height(node.right)) + 1
		else:
			if node.right:
				node = node.right
			else:
				node = node.left
		return node

	def traverse(self, func):
		if self.root is None:
			return -1
		else:
			return self._inorder_traverse(self.root, func)

	def _inorder_traverse(self, node, func):
		if node == None:
			return
		else:
			func(node)
			self._inorder_traverse(node.left, func)
			self._inorder_traverse(node.right, func)

'''
Event Queue, elements in which are nodes.
Attention: the nodes in the queue are sorted by py first, and if py of two points are the same, 
then they are sorted by px;
in other words, key in 
'''
class Event_Queue(AVLTree):
	def __init__(self):
		super().__init__()
		self.data = []

	def push(self, node):
		cur_node = self._find(node)
		if cur_node == None:
			self.put(node)
		else:
			'''
			if the point exists in the queue, then store the segment with the point
			'''
			cur_node.data.append(node.data)

	def pop(self):
		next_event = self._findMax(self.root)
		self.delete(next_event)
		return next_event


if __name__ == '__main__':
	datalist = [[i, i + 1] for i in range(10)]
	nodelist = []
	for data in datalist:
		nodelist.append(Node(data[0], data))
	tree = AVLTree()
	for node in nodelist:
		tree.put(node)
	tree.traverse(lambda x: print(x.data))