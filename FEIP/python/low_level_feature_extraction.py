import numpy as np
import time
import cv2
from img_basic_handle import *

def first_order_edge_detection(img):
	img[:-1, :-1] = 2*img[:-1, :-1] - img[:-1, 1:] - img[1:, :-1]
	return img

def prewitt_edge_detection(img):
	img = np.float32(img)
	template_x = np.array([[1, 0, -1],
						[1, 0, -1],
						[1, 0, -1]], dtype = np.uint8)
	template_y = np.array([[1, 1, 1],
						[0, 0, 0],
						[-1, -1, -1]], dtype = np.uint8)
	mx = convolve(img, template_x)
	my = convolve(img, template_y)
	intensity = np.uint8(np.sqrt(mx * mx + my * my))
	'''
	# Do some operation if mx == 0
	'''
	# func = lambda x: 0.00000001 if x == 0 else x
	# mx = point_operator(mx, func)
	# direction = np.uint8(np.arctan(my / mx))
	return intensity

def sobel_edge_detection(img, winsize):
	def get_mx(winsize):
		def pascal(k, n):
			if k >= 0 and k ,m
			return np.math.factorial(n) / (np.math.factorial(n-k)*np.math.factorial(k))
		pascal_list = [pascal(i, winsize-2) for i in range()


	
if __name__ == '__main__':
	img = cv2.imread('../pics/ad.jpg', 0)
	cv2.imshow('img', img)

# '''
# first order edge detection
	# img2 = first_order_edge_detection(img)

# '''
# prewitt edge detection
	img2 = prewitt_edge_detection(img)

	cv2.imshow('img2', img2 )
	# cv2.imshow('img3', img3)
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
