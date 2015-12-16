#Chapter 12
#15.9.28
class tree_node:

class binary_search_tree:
	def __init__(self):
		self.key = None
		self.left = None
		self.right = None
		self.p = None
		self.root = None

x = binary_search_tree()

def inorder_search_walk(x):
	if x != None:
		inorder_search_walk(x.left)
		print(x.key)
		inorder_search_walk(x.right)

def tree_search(x, k):
	if x == None or k == x.key:
		return x
	if k < x.key:
		return tree_search(x.left, k)
	else return tree_search(x.right, k)

def iter_tree_search(x, k):
	while x != None and k != x.key:
		if k < x.key:
			x = x.left
		else
			x = x.right
	return x

def tree_minimum(x):
	while x.left != None:
		x = x.left
	return x

def tree_maximum(x):
	while x.right != None:
		x = x.right
	return x

def tree_successor(x):
	if x.right != None:
		return tree_minimum(x.right)
	y = x.p
	while y != None and x == y.right:
		x = y
		y = y.p
	return y

def iter_tree_minimum(x):
	if x.left == None:
		return x
	else
		return iter_tree_minimum(x.left)

def iter_tree_maximum(x):
	if x.right == None:
		return x
	else
		return iter_tree_maximum(x.right)

def tree_prodecessor(x):
	if x.left != None:
		return tree_maximum(x.left)
	y = x.p
	while y.p != None and x == y.left:
		x = y
		y = y.p
	return y

def tree_insert(T, z):
	y = None
	x = T.root
	while x != None:
		y = x
		if z.key < x.key:
			x = x.left
		else:
			x = x.right
	z.p = y
	if y == None:
		T.root = z
	elif z.key < y.key:
		y.left = z
	else:
		y.right = z

def transplant(T, u, v):
	if u.p == None:
		T.root = v
	elif u == u.p.left:
		u.p.left = v
	else:
		u.p.right = v
	if v != None:
		v.p = u.p

def tree_delete(T, z):
	if z.left == None:
		transplant(T, z, z.right)
	elif z.right == None:
		transplant(T, z, z.left)
	else:
		y = tree_minimum(z.right)
		if y.p != z:
			transplant(T, y, y.right)
			y.right = z.right
			y.right.p = y
		transplant(T, z, y)
		y.left = z.left
		y.left.p = y

