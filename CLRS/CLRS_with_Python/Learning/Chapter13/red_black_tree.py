red = 'red'
black = 'black'


class node:
	def __init__(self):
		self.color = None
		self.parent = None
		self.left = None
		self.right = None
		self.key = None

class red_black_tree(node):
	def __init__(self):
		super().__init__()
		self.nil = None
		self.root = None

	def left_rotate(self, x):
		y = x.right
		x.right = y.left
		if y.left != self.nil: 
			y.left.p = x
		y.p = x.p
		if x.p == self.nil:
			self.root = y
		else if x == x.p.left:
			x.p.left = y
		else:
			x.p.right = y
		y.left = x
		x.p = y

	def right_rotate(self, y):
		x = y.left
		y.left = x.right
		if x.right != self.nil:
			x.right.p = y
		x.p = y.p
		if y.p == self.nil:
			self.root = x
		else if y = y.p.left:
			y.p.left = x
		else:
			y.p.right = x
		x.right = y
		y.p = x
	
	def insert(self, z):
		y = self.nil
		x = self.root
		while x != self.nil:
			y = x
			if z.key < x.key:
				x = x.left
			else:
				x = x.right
		z.p = y
		if y == self.nil:
			self.root = z
		elif z.key < y.key:
			y.left = z
		else:
			y.right = z
		z.left = self.nil
		z.right = self.nil
		z.color = red
		self.insert_fixup(self, z)

	def insert_fixup(self, z):
		while z.p.color == red:
			if z.p == z.p.p.left:
				y = z.p.p.right
				if y.color == red:
					z.p.color = black
					y.color = black
					z.p.p.color = red
					z = z.p.p
				elif z == z.p.right:
					z = z.p
					self.left_rotate(z)
				z.p.color = black
				z.p.p.color = red
				self.right_rotate(z.p.p)
			else:
				y = z.p.p.left
				if y.color == red:
					z.p.color = black
					y.color = black
					z.p.p.color = red
					z = z.p.p
				elif z == z.p.left:
					z = z.p
					self.right_rotate(z)
				z.p.color = black
				z.p.p.color = red
				self.left_rotate(z)
		self.root.color = black
