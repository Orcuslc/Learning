class Node:
	def __init__(self, n = 0, keys = [], leaf = True, child = [], t = 2):
		self.n = n
		self.keys = keys
		self.leaf = True
		self.child = child
		self.t = t

class BTree(Node):
	'''
	In this class, disk_read is a function to read data from the disk drive.
	'''
	def __init__(self):
		self.root = None
		
	def search(self, x, k):
		i = 1
		while i <= x.n and k > x.key:
			i += 1
		if i <= x.n and k == x.key:
			return x, i
		elif x.leaf:
			return None
		else:
			disk_read(x, child[i])
			return self.search(x.child[i], k)

	def create(self):
		'''
		allocate_node is a function to create a node into the disk drive.
		disk_write is a function to write data into the disk drive.
		'''
		x = allocate_node()
		x.leaf = True
		x.n = 0
		disk_write(x)
		self.root = x

	def split_child(self, x, i):
		z = allocate_node()
		y = x.child[i]
		z.leaf = y.leaf
		z.n = t - 1
		for j in range(t - 1):
			z.key[j] = y.key[j + t]
		if not y.leaf:
			for j in range(t):
				z.child[j] = y.child[j + t]
		y.n = t - 1
		for j in range(x.n, i, -1):
			x.child[j + 1] = x.child[j]
		x.child[j] = z
		for j in range(x.n, i, -1):
			x.key[j + 1] = x.key[j]
		x.key[i] = y.key[t]
		x.n = x.n + 1
		disk_write(y)
		disk_write(z)
		disk_write(x)

	def insert(self, k):
		r = self.root
		if r.n == 2 * self.t - 1:
			s = allocate_node()
			self.root = s
			s.leaf = False
			s.n = 0
			s.child[0] = r
			self.split_child(s, 0)
			insert_nonfull(s, k)
		else:
			self.insert_nonfull(r, k)

	def insert_nonfull(self, x, k):
		i = x.n
		if x.leaf:
			while i >= 0 and k < x.keys[i]:
				x.keys[i + 1] = x.keys[i]
				i -= 1
			x.keys[i + 1] = k
			x.n = x.n + 1	
			disk_write(x)
		else:
			while i >= 0 and k < x.keys[i]:
				i -= 1
			disk_read(x.child[i])
			if x.child[i].n == 2 * self.t - 1:
				self.split_child(x, i)
				if k > x.keys[i]:
					i += 1
			self.insert_nonfull(x.child[i], k)

	def delete(self, k):
		x, i = self.search(self.root, k)
		if x.leaf:
			for j in range(i, x.n):
				x.keys[j] = x.keys[j + 1]
				x.keys.pop(-1)
		else:
			

