#Exercise 10.4-2
#15.9.20

def print_tree(T):
	print (T.key)
	if T.left != nil:
		print_tree(T.left)
	if T.right != nil:
		print_tree(T.right)