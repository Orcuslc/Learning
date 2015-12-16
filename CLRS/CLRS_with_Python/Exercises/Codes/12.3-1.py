#exercise 12.3-1
#15.10.1

def iter_tree_insert(T, x):
	if T.root == None:
		T.root = x
	else:
		if T.root.key > x.key:
			return iter_tree_insert(T.left, x)
		else:
			return iter_tree_insert(T.right, x)
			