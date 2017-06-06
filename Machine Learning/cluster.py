import numpy as np 

def get_size(M):
	return list(M.shape)[:2]

def kmeans(M):
	'''
	M is a matrix with a structure of
	[[x11, x12, x13, ..., x1n, a1],
	[x21, x22, x23, ..., x2n, a2],
	...
	[[xm1, xn2, ..., xmn, am]]],

	'''
	