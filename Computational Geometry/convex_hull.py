# convex_hull
import matplotlib.pyplot as plt
import random

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
		for j in range(1, n):
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
	L_upper = [P[0], P[1]]
	for i in range(2, n):
		L_upper.append(P[i])
		while len(L_upper) >= 3 and is_right_turn(L_upper[-1], L_upper[-2], L_upper[-3]) == False:
			L_upper.pop(-2)
			L_upper.pop(-2)
	L_lower = [P[-1], P[-2]]
	for i in range(n - 3, -1):
		L_lower.append(P[i])
		while len(L_lower) >= 3 and is_right_turn(L_lower[-1], L_lower[-2], L_lower[-3]) == True:
			L_lower.pop(-2)
			L_lower.pop(-2)
	L_lower.pop(0)
	L_lower.pop(-1)
	L_upper.extend(L_lower)
	return L_upper

if __name__ == '__main__':
	P_x = [random.random() * 10 for i in range(10)]
	P_y = [random.random() * 10 for i in range(10)]
	P = [[P_x[i], P_y[i]] for i in range(len(P_x))]
	convex = convex_hull(P)
	P_x = [i[0] for i in P]
	P_y = [i[1] for i in P]
	convex_x = [i[0] for i in convex]
	convex_y = [i[1] for i in convex]
	plt.plot(P_x, P_y, 'r.')
	plt.plot(convex_x, convex_y, 'b')
	plt.show()

