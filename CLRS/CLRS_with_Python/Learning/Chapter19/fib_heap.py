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
	basic node in the tree, elem in which are type(element)
	'''
	def __init__(self, elem = None):
		self.elem = elem
		self.key = elem.key
		self.left = self
		self.right = self
		self.p = None
		self.child = None
		self.degree = 0
		self.mark = False

class fib_heap:
	'''
	the class of fibonacci heap, node in which are type(Node)
	'''
	def __init__(self):
		self.min = None
		self.n = 0

	def insert(self, node):
		node.degree = 0
		node.p = None
		node.child = None
		node.mark = False
		if self.min == None:
			node.left = node.right = node
			self.min = node
		else:
			x = self.min.left
			node = self.min.left
			node.left = x
			x.right = node
			if node.key < self.min.key:
				self.min = node
		self.n += 1

	def get_min(self):
		return self.min

	def _insert_new_for_union(self, node):
		if self.min == None:
			node.left = node.right = node
			self.min = node
		else:
			x = self.min.left
			node = self.min.left
			node.left = x
			x.right = node

	def union(self, another_heap):
		x = another_heap.min
		if x != None:
			self._insert_new_for_union(x)
			y = x.right
			while y != x:
				self._insert_new_for_union(y)
				y = y.right
		else:
			pass
		if self.min == None:
			self.min = x
		else:
			if x == None:
				pass
			else:
				if self.min.key > x.key:
					self.min = x
				else:
					pass
		self.n += another_heap.n

	def extract_min(self):
		z = self.min
		if z != None:
			y = z.child
			if y != None:
				self.insert(y)
				y.p = None
				x = y.right
				while x != y:
					self.insert(x)
					x.p = None
					x = x.right
			t = z.left
			s = z.right
			t.right = s
			s.left = t
			if z == z.right:
				self.min = None
			else:
				self.min = z.right
				self._consolidate()
			self.n -= 1
		return z

	def _d(self):
		pass

	def _exchange_nodes(self, x, y):
		x.left.right = y
		x.right.left = y
		y.left.right = y
		y.right.left = x

	def _consolidate(self):
		A = [None for i in range(self._d() + 1)]
		x = self.min
		d = x.degree
		while A[d] != None:
			y = A[d]
			if x.key > y.key:
				self._exchange_nodes(x, y)
			self._heap_link(y, x)
			A[d] = None
			d += 1
		A[d] = x
		while (y = x.right) != x:
			z = y
			d = z.degree
			while A[d] != None:
				t = A[d]
				if z.key > t.key:
					self._exchange_nodes(z, t)
				self._heap_link(t, z)
				A[d] = None
				d += 1
			A[d] = z
		self.min = None
		for i in range(0, self._d() + 1):
			if A[i] != None:
				if self.min == None:
					self.min = A[i]
					A[i].left = A[i].right = A[i]
				else:
					self._insert_new_for_union(A[i])
					if A[i].key < self.min.key:
						self.min = A[i]

	def _heap_link(self, y, x):
		y.left.right = y.right
		y.right.left = y.left
		y.left = x.child.left
		y.right = x.child
		x.child.left.right = y
		x.child.left = y
		x.degree += 1
		y.mark = False

	def decrease_key(self, x, k):
		if k > x.key:
			raise Exception('New key is greater than current key')
		x.key = k
		y = x.p
		if y != None and x.key < y.key:
			self._cut(x, y):
			self._cascading_cut(y):
		if x.key < self.min.key:
			self.min = x

	def _cut(self, x, y):
		x.left.right = x.right
		x.right.left = x.left
		y.degree -= 1
		x.left = self.min.left
		x.right = self.min
		self.min.left.right = x
		self.min.left = x
		x.p = None
		x.mark = False

	def _cascading_cut(self, y):
		z = y.p
		if z != None:
			if y.mark == False:
				y.mark = True
			else:
				self._cut(y, z)
				self._cascading_cut(z)

	def delete(self, x):
		self.decrease_key(x, float('-inf'))
		self.extract_min()