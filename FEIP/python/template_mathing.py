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
	accum = np.zeros([row, col], dtype = np.uint8)
	tc = np.floor(col) + 1
	tr = np.floor(row) + 1
	for i in range()