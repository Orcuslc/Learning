import numpy as np
import time
import cv2
from img_basic_handle import *

def first_order_edge_detection(img):
	img[:-1, :-1] = 2*img[:-1, :-1] - img[:-1, 1:] - img[1:, :-1]
	return img

def prewitt_edge_detection(img):
	template_x = np.array([[1, 0, -1],
						[1, 0, -1],
						[1, 0, -1]], dtype = uint8)
	template_y = np.array([[1, 1, 1],
						[0, 0, 0],
						[-1, -1, -1]])
	mx = convolve(img, template_x)
	my = convolve(img, template_y)
	intensity = np.uint8(np.sqrt(mx * mx + my * my))
	direction = np.uint8(np.arctan(my / mx))
	return intensity, direction

if __name__ == '__main__':
	img = cv2.imread('../pics/ad.jpg', 0)
	cv2.imshow('img', img)

# '''
# first order edge detection
	img2 = first_order_edge_detection(img)

	cv2.imshow('img2', img2 )
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
