def search(a):
	if len(a) == 2:
		if a[0] < a[1]:
			return a[::-1]
		else:
			return None
	else:
		b = search(a[1:])
		if b != None:
			return [a[0]] + b
		else:
			c = a[1:]
			for index, value in enumerate(c):
				if value <= a[0]:
					break
			else:
				index = len(c)
			if index == 0:
				return None
			else:
				a[0], c[index - 1] = c[index - 1], a[0]
				return [a[0]] + c[::-1]
				
if __name__ == '__main__':
	a = [1, 0, 0, 9, 8, 7, 6]
	b = search(a)
	print(b)