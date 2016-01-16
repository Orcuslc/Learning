# convex_hull
import matplotlib.pyplot as plt

def convex_hull(P):
	'''
	input: a list of points P, points in which has a format of [x, y]
	output: a list of points Q, which is the convex hull of P
	'''
	n = len(P)
	if n <= 3:
		return P
	def sort_by_x(P):
		'''
		using insertion sort to sort the list of points P
		'''
		n = len(P)
		for j in range(1, n - 1):
			backup = P[j]
			key = P[j][0]
			i = j - 1
			while i >= 0 and P[i][0] > key:
				P[i + 1] = P[i]
				i -= 1
			P[i + 1] = backup
		return P

	def is_right_turn(a, b, c):
		'''
		check if three points make a right turn,
		where the input points have a format of [x, y]
		'''
		if b[1] < c[1]:
			return False
		else:
			return True

	P = sort_by_x(P)
	L_supper = [P[0], P[1]]
	for i in range(2, n - 1):
		L_supper.append(P[i])
		while len(L_supper) >= 3 and is_right_turn(L_supper[-1], L_supper[-2], L_supper[-3]) == False:
			L_supper.pop(-2)
			L_supper.pop(-2)
	L_lower = [P[-1], P[-2]]
	


