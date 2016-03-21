import math
import len_vec_c
import time
import numpy as np
import len_vec_swig


def lenv(vec):
	'''
	input: a list, like [11, 1, 1, 0]
	'''
	return math.sqrt(sum([i*i for i in range(vec)]))

def lenv3(vec):
	return np.sqrt(np.array([i*i for i in range(vec)]).sum())

if __name__ == '__main__':
	# vec = 1000;
	# start1 = time.time()
	# length1 = lenv(vec)
	# end1 = time.time()
	# np.sum(1)

	# start2 = time.time()
	# length2 = len_vec_c.lenv2(vec)
	# end2 = time.time()

	# start3 = time.time()
	# length3 = lenv3(vec)
	# end3 = time.time()

	# print(length1)
	# print(length2)
	# print("time1:", end1 - start1)
	# print("time2:", end2 - start2)
	# print(length3)
	# print("time3:", end3 - start3)
	n = 100
	vec = [n] + [i for i in range(100)]
	length4 = len_vec_swig.lenv4(vec)
	print(length4)
	