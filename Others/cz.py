import numpy as np
from matplotlib import pyplot as plt
import random as rd

def sim():
	T = 1
	N = 500
	dt = T/N
	t = np.linspace(dt, T, num = N, endpoint=True)
	dW = np.sqrt(dt)*np.random.randn(1, N)
	W = dW.sum()
	return np.sin(np.abs(W))*np.exp(W)

def test(n):
	res = np.zeros(n)
	for i in range(n):
		res[i] = sim()
	return np.exp(1/2)*np.mean(res)+np.exp(1)-1

if __name__ == '__main__':
	print(test(100000))