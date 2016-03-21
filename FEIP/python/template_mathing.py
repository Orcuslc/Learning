import cv2
import numpy as np
import time
from img_basic_handle import *
from scipy.ndimage import convolve

def MLE_template_matching(img, temp):
	'''
	Attention: The template input should be like 
	a rectangle with its elements belong to {0, 1}.

	Example:
		temp = np.array([[1, 0, 0],
						[0, 1, 0],
						[0, 0, 1]])

	Return: A np.array accum of the error of matching.
	'''
	[row, col] = get_size(img)
	[row_t, col_t] = get_size(temp)
	tsum = temp.sum()
	accum = np.zeros([row, col], dtype = np.uint8)
	tc = np.int(np.floor(col_t/2)+1)
	tr = np.int(np.floor(row_t/2)+1)
	for i in range(tr-1, row-tr):
		for j in range(tc-1, col-tc):
			accum[i, j] = ((np.float32(img[i-tr+1:i+tr-1, j-tc+1:j+tc-1]) - np.float32(temp))**2).sum()/tsum
			# for x in range(1-tr, tr-1):
			# 	for y in range(1-tc, tc-1):
			# 		accum[i, j] += (np.float32(img[i+x, j+y]) - np.float32(temp[tr+x-1, tc+y-1])) **2
	return accum

if __name__ == '__main__':
	img = cv2.imread('../pics/cat.jpg', 0)
	cv2.imshow('img',img)
	# print(img.shape)
	
	# temp = img[200:400,200:300]
	temp = np.array([[i*10 for i in range(200)] for i in range(200)], dtype=np.uint8)
	# temp = cv2.imread('../pics/ad.jpg', 0)[::2,::2]
	cv2.imshow('temp', temp)

	img2 = MLE_template_matching(img, temp)
	

	cv2.imshow('img2', img2)
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
