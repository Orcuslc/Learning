from img_basic_handle import *
import numpy as np
import cv2
import time

def amplify_img(img):
	'''
	The original image is like this:

	a11 a12 a13 ... a1n
	a21 a22 a23 ... a2n
	...
	an1 an2 an3 ... ann

	The amplified image is like this:

	a11 b11 a12 b12 ... a1n b1n
	c11 c12 c13 c14 ... c1(2n-1) c1(2n)
	a21 b21 a22 b22 ... a2n b2n
	...
	an1 bn1 an2 bn2 ... ann bnn
	cn1 cn2 cn3 cn4 ... cn(2n-1) cn(2n)

	in which b(i, j) = (a(i, j) + a(i, j+1)) / 2,
	c(i, 2*j-1) = (a(i, 2*j-1) + a(i+1, 2*j-1)) / 2,
	and c(i, 2*j) = (b(i, j) + b(i+1, j)) / 2

	b(i, n) = a(i, n)
	'''
	[row, col] = get_size(img)
	temp = np.zeros([2*row, 2*col], dtype = np.uint8)
	# for i in range(row):
	'''
	a
	'''
	temp[::2, ::2] = img[:, :]
	'''
	b
	'''
	temp[::2, 1:2*col - 2:2] = np.uint8((img[:, :-1] + img[:, 1:]) / 2)
	'''
	b(i, n)
	'''
	temp[::2, 2*col - 1] = img[:, col - 1]
	
	# for i in range(row - 1):
	# 	'''
	# 	c(0:2*row - 1, :)
	# 	'''
	# 	temp[2 * i + 1, :] =  np.uint8((temp[2 * i, :] + temp[2 * i + 2, :]) / 2)
	# print(temp[1::2, :].shape)
	# print(temp[:-1:2, :].shape)
	# print(temp[2::2, :].shape)
	temp[1:-1:2, :] = np.uint8((temp[:-2:2, :] + temp[2::2, :])/2)
	'''
	c(2 * row - 1, :)
	'''
	temp[2 * row - 1, :] = temp[2 * row - 2, :]
	return temp

def amplify(img):
	amplified = amplify_img(img)
	return anisotropic_diffusion_operator(amplified)

if __name__ == '__main__':
	img = cv2.imread('../pics/ad.jpg', 0)
	cv2.imshow('img', img)

	# amplify
	start = time.time()
	img2 = amplify(img)
	end = time.time()
	print('time:', end - start)
	
	cv2.imshow('img2', img2)
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
