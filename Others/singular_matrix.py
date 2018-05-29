import numpy as np

## brute-force
zero = 0
nonzero = 0
m = np.zeros((10, 10))
for i in range(10):
	for j in range(10):
		m[i, j] = 