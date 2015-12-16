#exercise 7.1
#15.12.9
#chuanlu

import numpy as np

def fixed_point_iter(func, x0, tol = 1e-8):
	count = 0
	while True:
		count += 1
		x1 = func(x0)
		print(x1)
		if abs(x1 - x0) < tol:
			break
		x0 = x1
	return x1, count

def steffensen_accelerated_iter(func, x0, tol = 1e-8):
	count = 0
	while True:
		count += 1
		y = func(x0)
		z = func(y)
		x1 = x0 - ((y - x0) **2) / (z - 2 * y + x0)
		print(x1)
		if abs(x1 - x0) < tol:
			break 
		x0 = x1
	return x1, count

def newton_iter(func1, func2, x0, tol = 1e-8):
	count = 0
	f1 = func1(x0)
	f2 = func2(x0)
	while True:
		count += 1
		x1 = x0 - f1 / f2
		print(x1)
		f1 = func1(x1)
		f2 = func2(x1)
		if abs(x1 - x0) < tol:
			break 
		x0 = x1
	return x1, count

def main():
	print("exercise7.1.2")
	#question7.1.1
	x0 = 0.5
	func = lambda x: (x**2 + 2 - np.exp(x))/3
	func1 = lambda x: x ** 2 - 3 * x + 2 - np.exp(x)
	func2 = lambda x: 2 * x - 3 - np.exp(x)
	print("fixed_point_iter")
	result, count = fixed_point_iter(func, x0)
	print("result:", result)
	print("count:", count)
	print("steffensen_accelerated_iter")
	result, count = steffensen_accelerated_iter(func, x0)
	print("result:", result)
	print("count:", count)
	print("newton_iter")
	result, count = newton_iter(func1, func2, x0)
	print("result:", result)
	print("count:", count)
	
	#question7.1.2
	print("exercise7.1.2")
	x0 = 1
	func = lambda x: (28 - 7*x) ** (1/3)
	func1 = lambda x: x**3 + 2*(x**2) + 10*x - 20
	func2 = lambda x: 3*(x**2) + 4*x + 10
	print("fixed_point_iter")
	result, count = fixed_point_iter(func, x0)
	print("result:", result)
	print("count:", count)
	print("steffensen_accelerated_iter")
	result, count = steffensen_accelerated_iter(func, x0)
	print("result:", result)
	print("count:", count)
	print("newton_iter")
	result, count = newton_iter(func1, func2, x0)
	print("result:", result)
	print("count:", count)



if __name__ == '__main__':
	main()