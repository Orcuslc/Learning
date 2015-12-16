#exercise5.3
#15.11.4
#author: chuanlu

from exercise2 import *
import numpy as np

def _q3():
	A = np.matrix([[10,7, 8, 7],
					[7, 5, 6, 5],
					[8, 6, 10, 9],
					[7, 5, 9, 10]])
	detA = np.linalg.det(A)
	print("detA:", detA)
	eig_val, eig_array = np.linalg.eig(A)
	print("eig_val:", eig_val)
	cond2A = np.linalg.cond(A, p = 2)
	print("cond2A:", cond2A)
	b = np.matrix([[32], [23], [33], [31]])
	x = np.linalg.solve(A, b)
	A_plus_delta_A = np.matrix([[10, 7, 8.1, 7.2],
						[7.08, 5.04, 6, 5],
						[8, 5.98, 9.89, 9],
						[6.99, 5, 9, 9.98]])
	delta_x = np.linalg.solve(A_plus_delta_A, b) - x
	print("delta_x:", delta_x)
	norm2_delta_x = np.linalg.norm(delta_x, 2)
	print("norm2_delta_x:", norm2_delta_x)
	relative_error_x = norm2_delta_x / np.linalg.norm(x,2)
	print("relative_error_x:", relative_error_x)
	delta_A = A_plus_delta_A - A
	relative_error_A = np.linalg.norm(delta_A, 2) / np.linalg.norm(A, 2)
	print("relative_error_A:", relative_error_A)

def main():
	_q3()

if __name__ == '__main__':
	main()







