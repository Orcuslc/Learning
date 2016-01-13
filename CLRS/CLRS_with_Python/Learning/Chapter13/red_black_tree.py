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

	def transplant(self, u, v):
		if u.p == self.nil:
			self.root = v
		elif u == u.p.left:
			u.p.left = v
		else:
			u.p.right = v
		v.p = u.p

	def delete(self, z):
		y = z
		y_original_color = y.color
		if z.left == self.nil:
			x = z.right
			self.transplant(z, z.right)
		elif z.right == T.nil:
			x = z.left
			self.transplant(z, z.left)
		else:
			y = self.tree_minimum(z.right)
			y_original_color = y.color
			x = y.right
			if y.p == z:
				x.p = y
			else:
				self.transplant(y, y.right)
				y.right = z.right
				y.right.p = y
			self.transplant(z, y)
			y.left = z.left
			y.left.p = y
			y.color = z.color
		if y_original_color == black:
			self.delete_fixup(x)

	def delete_fixup(self, x):
		while x != self.root and x.color == black:
			if x == x.p.left:
				w = x.p.right
				if w.color == red:
					w.color = black
					x.p.color = red
					self.left_rotate(x.p)
					w = x.p.right
				if w.left.color == black and w.right.color == black:
					w.color = red
					x = x.p
				elif w.right.color == black:
					w.left.color = black
					w.color = red
					self.right_rotate(w)
					w = x.p.right
				w.color = x.p.color
				x.p.color = black
				w.right.color = black
				self.left_rotate(x.p)
				x = self.root
			else:
				w = x.p.left
				if w.color == red:
					w.color = black
					x.p.color = red
					self.right_rotate(x.p)
					w = x.p.left
				if w.right.color == black and w.left.color == black:
					w.color = red
					x = x.p
				elif w.left.color == black:
					w.right.color = black
					w.color = red
					self.left_rotate(w)
					w = x.p.left
				w.color = x.p.color
				x.p.color = black
				w.left.color = black
				self.right_rotate(x.p)
				x = self.root
		x.color = black
