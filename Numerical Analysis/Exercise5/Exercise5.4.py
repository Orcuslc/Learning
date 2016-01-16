#exercise 5.4
#15.11.11
#author: chuanlu

import numpy as np
from exercise2 import * 

def _init_hilbert_matrix(n):
	h = np.zeros([n, n])
	h += 0.0
	for i in range(n):
		for j in range(n):
			h[i, j] = 1/( i + j + 1 )
	return h

def _q1():
	for n in range(2, 7):
		h = _init_hilbert_matrix(n)
		cond_h = np.linalg.cond(h, -np.inf)
		print("n:%d, cond_h:%f" %(n, cond_h))

def _q2():
	for n in range(2, 10):
		h = _init_hilbert_matrix(n)
		x = np.zeros([n, 1])
		b = np.dot(h, x)
		calc_x = column_pivoting_gauss_elimination(h, b)
		r = b - np.dot(h, calc_x)
		delta_x = calc_x - x
		print("n:", n)
		print("calc_x:", x)
		print("r:", r)
		print("delta_x:", delta_x)
		print("%n")


def main():
	# _q1()
	_q2()

if __name__ == '__main__':
	main()