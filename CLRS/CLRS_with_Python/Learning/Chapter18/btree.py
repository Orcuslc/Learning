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
			return btree_search(x.child[i], k)

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

	def 
