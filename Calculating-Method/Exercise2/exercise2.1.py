#exercise 2.1
#15.9.24
#author: chuanlu
import numpy as np
import sympy
import matplotlib.pyplot as plt

x = sympy.Symbol('x')

def newton_interpolation(args, x_values):
	value = args[0]
	for i in range(1, len(args)):
		temp = 1
		for j in range(i):
			temp *= (x - x_values[j])
		value += args[i] * temp
	return value

def get_value(f, value):
	return f.subs(x, value)

def newton_coefficient(x_values, f_values):
	for i in range(len(f_values) - 2):
		f_values[i + 1:] = (f_values[i + 1:] - f_values[i: len(f_values) - 1])/(x_values[i + 1:] - x_values[: len(x_values) - i - 1])
	return f_values

def newton_eval():
	x_values = np.array([0.2, 0.4, 0.6, 0.8, 1.0])
	f_values = np.array([0.98, 0.92, 0.81, 0.64, 0.38])
	args = newton_coefficient(x_values, f_values)
	newton_func = newton_interpolation(args, x_values)
	x_list = [0.2 + 0.08 * i for i in range(11)]
	y_list = [get_value(newton_func, i) for i in x_list]
	plt.plot(x_list, y_list)
	plt.show()

def natural_spline_func(x_values, f_values):
	n = len(x_values)
	h = x_values[1:] - x_values[:-1]
	delta_f = f_values[1:] - f_values[:-1]
	d = np.array([0.0 for i in range(n)])
	d[1: n - 1] = 6*(delta_f[1:]/h[1:] - delta_f[:-1]/h[:-1])
	s3 = np.array([0.0 for i in range(n - 1)])
	s3[:-1] = h[:-1]
	s2 = np.array([1.0 for i in range(n)])
	s2[1: n - 1] = 2*(h[:-1] + h[1:])
	s1 = np.array([0.0 for i in range(n - 1)])
	s1[1:] = h[1:]
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

def natural_spline_eval():
	x_values = np.array([0.2, 0.4, 0.6, 0.8, 1.0])
	f_values = np.array([0.98, 0.92, 0.81, 0.64, 0.38])
	x_list = [0.2 + 0.08 * i for i in range(11)]
	func_list = natural_spline_func(x_values, f_values)
	value_list = []
	for x in x_list:
		for i in range(len(x_values)):
			if x_values[i] <= x <= x_values[i+1]:
				value_list.append(get_value(func_list[i], x))
				break

	print(func_list)
	print(value_list)
	plt.plot(x_list, value_list)
	plt.show()

if __name__ == '__main__':
	newton_eval()
	natural_spline_eval()