import numpy as np
import cv2


with open('../data/test2.csv') as f:
	d = f.read().split('\n')[:-1]
	d = [i.split(',') for i in d]
	d = [[float(i) for i in a] for a in d]
	# print(d)
	d = np.asmatrix(d, dtype=np.uint8)

for k in [1, 2, 3, 4, 5, 10, 20, 50, 200]:
	u, s, v = np.linalg.svd(d)
	u1 = u[:, :k]
	s1 = np.diag(s[:k])
	v1 = v[:k, :]
	d2 = np.dot(u1, np.dot(s1, v1))
	d2 = np.asmatrix(d2, dtype=np.uint8)
	cv2.imshow('img'+str(k), d2)
cv2.imshow('img', d)

cv2.waitKey(0)