#exercise 2.3
#15.9.24
#author: chuanlu
import numpy as np
import matplotlib.pyplot as plt
import sympy

x = sympy.Symbol('x')

def get_value(f, value):
	return f.subs(x, value)

def lagrange_func(x_values, f_values):
	sum_n = 0
	for i in range(len(x_values)):
		temp = 1
		for j in range(len(x_values)):
			if j != i:
				temp *= (x - x_values[j])/(x_values[i] - x_values[j])
		sum_n += temp*f_values[i]
	return sum_n

def lagrange_eval():
	x_values = [0,1,4,9,16,25,36,49,64]
	f_values = [0,1,2,3,4,5,6,7,8]
	x_list = [i for i in range(64)]
	value_list = []
	func = lagrange_func(x_values, f_values)
	for x in x_list:
		value_list.append(get_value(func, x))
	plt.plot(x_list, value_list)
	plt.show()
	print(get_value(func, 49))

def first_spline_func(x_values, f_values, f1, f2):
	n = len(x_values)
	h = x_values[1:] - x_values[:-1]
	delta_f = f_values[1:] - f_values[:-1]
	d = np.array([0.0 for i in range(n)])
	d[1: n - 1] = 6*(delta_f[1:]/h[1:] - delta_f[:-1]/h[:-1])
	d[0] = 6*(f_values[1] - f_values[0] - f1 * h[0])/(h[0]**2)
	d[-1] = 6*(f2 - (f_values[-1] - f_values[-2])/h[-2])/h[-1]
	s3 = d
	s1 = d
	s2 = np.array([1.0 for i in range(n)])
	s2[0] = 2*h[0]
	s2[-1] = 2*h[-1]
	s2[1: n - 1] = 2*(h[:-1] + h[1:])
	m = solve_tdma(s3, s2, s1, d)
	a = f_values
	b = (f_values[1:] - f_values[:-1])/h[:] - h[:]*m[:-1]/2 - h[:]*(m[1:] - m[:-1])/6
	c = m[:-1]/2
	d = (m[1:] - m[:-1])/(6*h[:])
	func_list = []
	for i in range(len(a) - 1):
		func_list.append(a[i] + b[i]*(x-x_values[i]) + c[i]*(x - x_values[i])**2 + d[i]*(x - x_values[i])**3)
	return func_list

def solve_tdma(a, b, c, d):
	c[0] = c[0] / b[0]
	d[0] = d[0] / b[0]
	for i in range(1, len(d) - 1):
		m = 1/(b[i] - a[i] *c[i-1])
		c[i] = c[i] * m
		d[i] = (d[i] - a[i] * d[i - 1]) * m
	for i in range(len(d) - 2, -1, -1):
		d[i] = d[i] - c[i - 1] * d[i+1]
	return d

def first_spline_eval():
	f1 = 0
	f2 = 1/16
	x_values = np.array([0,1,4,9,16,25,36,49,64])
	f_values = np.array([0,1,2,3,4,5,6,7,8])
	x_list = [i for i in range(64)]
	value_list = []
	func_list = first_spline_func(x_values, f_values, f1, f2)
	value_list = []
	for x in x_list:
		for i in range(len(x_values)):
			if x_values[i] <= x <= x_values[i+1]:
				value_list.append(get_value(func_list[i], x))
				break
	plt.plot(x_list, value_list)
	plt.show()

if __name__ == '__main__':
	lagrange_eval()
	first_spline_eval()