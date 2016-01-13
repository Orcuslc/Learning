from Chapter13.red_black_tree import red_black_tree, node

class order_statistic_node(node):
	def __init__(self):
		super().__init__()
		self.size = 0

class order_statistic_tree(red_black_tree):
	def __init__(self):
		super().__init__()
		x.

	def os_select(self, x, i):
		r = x.left.size + 1
