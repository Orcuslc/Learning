import random as rd
import math
import numpy as np
from matplotlib import pyplot as plt

def walk_astep(memory, q, step = 1):
	u = rd.random()
	if u <= q:
		memory.append(step)
	else:
		memory.append(-1*step)

def random_choice(k, alpha):
	u = rd.random()
	# if alpha == 1.0:
	# 	return math.ceil(alpha*k)
	if k <= 5:
		if alpha == 1.0:
			return math.ceil(u*k)
		return math.ceil(math.log((alpha**k-1)*u+1, alpha))
	else:
		if alpha == 1.0:
			return math.ceil(u*5)+(k-6)
		return math.ceil(math.log((alpha**5-1)*u+1, alpha))+(k-6)
	# return math.ceil(u*k)

def walk(n, p, q, alpha):
	memory = [0]
	for i in range(1, n+1):
		if i == 1:
			walk_astep(memory, q, 1)
		else:
			mem = random_choice(i-1, alpha)
			# print(mem)
			walk_astep(memory, p, memory[mem])
	return np.cumsum(memory)


if __name__ == '__main__':
	# memory = walk(1000000, 1/3, 2/3, 1)
	num = 1000
	n = 100000
	count = 0
	for p in [1/3, 2/3]:
		for q in [1/3, 2/3]:
			count += 1
			plt.figure(count)
			sub = 0
			# for alpha in [1, 1.25, 1.5, 1.75, 2]:
			for alpha in [1]:
				memory = np.zeros(n+1)
				sub += 1
				for i in range(num):
					# print(i)
					memory += walk(n, p, q, alpha)
					# print(len(memory))
				memory /= num
				# memory = memory[np.where(memory > 0)]
				# plt.subplot(510+sub)
				plt.plot(np.log(np.array(range(1, len(memory)))), np.log(memory[1:]))

	# for p in [1/3]:
	# 	for q in [1/3, 2/3]:
	# 		count += 1
	# 		plt.figure(count)
	# 		for alpha in [1, 1.25, 1.5, 1.75, 2]:
	# 			memory = walk(n, p, q, alpha)
	# 			plt.plot(np.array(range(1, n+1)), memory[1:])
	# memory = np.zeros(n+1)
	# for i in range(num):
	# 				# print(i)
	# 	memory += walk(n, 2/3, 2/3, alpha = 1)
	# 				# print(len(memory))
	# memory /= num
	plt.plot(np.log(range(1, n+1)), np.log(memory[1:]))
	# plt.plot(range(1, n+1), memory[1:])
	plt.show()

