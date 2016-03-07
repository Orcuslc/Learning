import numpy as np
import cv2
import matplotlib.pyplot as plt
import copy

def histogram(img):
	pixels_at_level = np.zeros([1, 256])[0]
	for row in img:
		for col in row:
			pixels_at_level[col] += 1
	# plt.hist(pixels_at_level, 100)
	# plt.show()
	return pixels_at_level

def point_operator(img, func):
	[row, col] = list(img.shape)[:2]
	for i in range(row):
		for j in range(col):
			img[i][j] = func(img[i][j])
	return img

def histogram_normalization(img):
	[row, col] = list(img.shape)[:2]
	shaped_img = img.reshape(1, img.size)
	maxim = shaped_img.max(1)[0]
	minim = shaped_img.min(1)[0]
	rangeim = maxim - minim
	for i in range(row):
		for j in range(col):
			img[i][j] = (img[i][j] - minim) * 255 / rangeim;
	return img

def histogram_equalization(img):
	rangeim = 255
	number = img.size
	pixels_at_level= [0 for i in range(rangeim + 1)]
	[row, col] = list(img.shape)[:2]
	for i in range(col):
		for j in range(row):
			pixels_at_level[img[i][j]] += 1
	hist = [0 for i in range(rangeim + 1)]
	sumim = 0
	for i in range(rangeim):
		sumim += pixels_at_level[i]
		hist[i] = rangeim/number * sumim
	for i in range(col):
		for j in range(row):
			img[i][j] = hist[img[i][j]]
	return img

def uniformed_thresholding(img, threshold):
	[row, col] = list(img.shape)[:2]
	for i in range(row):
		for j in range(col):
			if img[i][j] < threshold:
				img[i][j] = 0
			else:
				img[i][j] = 255
	return img

def ostu_thresholding(img):
	N = 255
	[row, col] = list(img.shape)[:2]
	pixels_at_level = histogram(img) / (row * col)
	mu = lambda k, pixel: sum([(i+1) * pixel[i] for i in range(k)])
	omega = lambda k, pixel: sum([pixel[i] for i in range(k)])
	mu_T = lambda pixel:sum([(i+1) * pixel[i] for i in range(N+1)])
	values = np.zeros(N + 1)
	mu_T_img = mu_T(pixels_at_level)
	for k in range(1, N+1):
		omega_k = omega(k, pixels_at_level)
		mu_k = mu(k, pixels_at_level)
		delta = (mu_T_img * omega_k - mu_k) ** 2 / (omega_k * (1 - omega_k))
		values[k] = delta
	# print(values)
	img = uniformed_thresholding(img, values.argmax(0))
	return img, values.argmax(0)

def convolve(img, template):
	[irow, icol] = list(img.shape)[:2]
	[trow, tcol] = list(template.shape)[:2]
	temp = np.zeros([irow, icol])
	trhalf = int(np.floor(trow/2))
	tchalf = int(np.floor(tcol/2))
	for x in range(trhalf, icol - trhalf + 1):
		for y in range(tchalf, irow - tchalf + 1):
			sumim = 0
			for iwin in range(trow - 1):
				for jwin in range(tcol - 1):
					sumim += img[y + jwin - trhalf][x + iwin - trhalf] * template[jwin][iwin]
			temp[y][x] = sumim
	# print(temp)
	return histogram_normalization(temp)
	# return temp

if __name__ == '__main__':
	img = cv2.imread('../pics/ad.jpg', 0)
	cv2.imshow('img', img)
	# histogram(img)

	# linear operator
	# func = lambda x: x*10
	
	# sawtooth operator
	# func = lambda x: x % 50

	# logarithmic point operator
	# func = lambda x: 20 * np.log(100 * x)

	# img2 = point_operator(img, func)

	# normalization
	# img2 = histogram_normalization(img)
	
	# histogram(img2)

	# equalization
	# img2 = histogram_equalization(img)

	# uniformed_thresholding
	# img2 = uniformed_thresholding(img, threshold = 150)

	# Otsu_thresholding
	# img = cv2.imread('../pics/1.jpg', 0)
	# cv2.imshow('img', img)
	# img2, threshold = ostu_thresholding(img)
	# print(threshold)
	
	# Convolve
	template = np.array([[1/9, 1/9, 1/9], [1/9, 1/9, 1/9], [1/9, 1/9, 1/9]])
	img2 = convolve(img, template)

	cv2.imshow('img2', img2)
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
