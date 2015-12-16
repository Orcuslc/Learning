#Exercise 10.4-3

#对于这个二叉树，我们可以取一个栈；
#push进栈的时候print左子树，pop出栈的时候print右子树

def print_tree(tree, stack):
	print(tree.key)
	stack.push(tree)
	while True:
		if (tree.left != nil):
			tree = tree.left

		else:
			while True:
				tree = stack.pop()
				if tree == nil:
					return 0
				if tree.left != nil:
					break
			tree = tree.right