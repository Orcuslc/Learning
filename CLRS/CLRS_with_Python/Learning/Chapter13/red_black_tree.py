class red_black_tree:
	def __init__(self):
		self.nil = None

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
	
