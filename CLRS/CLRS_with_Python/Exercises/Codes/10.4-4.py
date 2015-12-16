#Exercise 10.4-4
#15.9.21

def print_tree(T):
	print(T.key)
	x = T.left-child
	while x != nil:
		print_tree(x)
		x = x.right-sibiling
	