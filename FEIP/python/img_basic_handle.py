import numpy as np
import cv2
import matplotlib.pyplot as plt
import copy
import time

def get_size(img):
	return list(img.shape)[:2]

# def histogram1(img):
# 	pixels_at_level = np.zeros([1, 256])[0]
# 	for row in img:
# 		for col in row:
# 			pixels_at_level[col] += 1
# 	# plt.hist(pixels_at_level, 100)
# 	# plt.show()
# 	# print(pixels_at_level)
# 	return pixels_at_level

def histogram(img):
	# pixels_at_level = np.zeros([1, 256], dtype = np.int)[0]
	img = img.reshape(1, img.size)[0]
	# levels = np.unique(img)
	weight = np.bincount(img)
	return weight
	# for index in range(len(levels)):
	# 	nindex = levels[index]
	# 	# print(nindex)
	# 	# print(weight[index])
	# 	pixels_at_level[levels[index]] = weight[index]
	# return pixels_at_level

# def point_operator1(img, func):
# 	[row, col] = get_size(img)
# 	for i in range(row):
# 		for j in range(col):
# 			img[i][j] = func(img[i][j])
# 	return img

def point_operator(img, func):
	f = np.vectorize(func)
	return np.uint8(f(img))

# def histogram_normalization1(img):
# 	[row, col] = get_size(img)
# 	shaped_img = img.reshape(1, img.size)
# 	maxim = shaped_img.max(1)[0]
# 	minim = shaped_img.min(1)[0]
# 	rangeim = maxim - minim
# 	for i in range(row):
# 		for j in range(col):
# 			img[i][j] = (img[i][j] - minim) * 255 / rangeim;
# 	return img

def histogram_normalization(img):
	shaped_img = img.reshape(1, img.size)
	maxim = shaped_img.max(1)[0]
	minim = shaped_img.min(1)[0]
	rangeim = maxim - minim
	normf = lambda x : (x - minim) * 255 / rangeim
	return point_operator(img, normf)

# def histogram_equalization1(img2):
# 	img = copy.deepcopy(img2)
# 	rangeim = 255
# 	number = img.size
# 	pixels_at_level= [0 for i in range(rangeim + 1)]
# 	[row, col] = get_size(img)
# 	for i in range(col):
# 		for j in range(row):
# 			pixels_at_level[img[j][i]] += 1
# 	hist = [0 for i in range(rangeim + 1)]
# 	sumim = 0
# 	for i in range(rangeim):
# 		sumim += pixels_at_level[i]
# 		hist[i] = rangeim/number * sumim
# 	for i in range(col):
# 		for j in range(row):
# 			img[j][i] = hist[img[j][i]]
# 	return img

def histogram_equalization(img):
	rangeim = 255
	number = img.size
	[row, col] = get_size(img)
	weight = np.bincount(img.reshape(1, img.size)[0])
	global hist	
	hist = [0 for i in range(rangeim + 1)]
	sumim = 0
	for i in range(rangeim):
		sumim += weight[i]
		hist[i] = rangeim/number * sumim
	func = lambda x: hist[x]
	return point_operator(img, func)
	

def uniformed_thresholding(img, threshold):
	[row, col] = get_size(img)
	for i in range(row):
		for j in range(col):
			if img[i][j] < threshold:
				img[i][j] = 0
			else:
				img[i][j] = 255
	return img

def ostu_thresholding(img):
	N = 255
	[row, col] = get_size(img)
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
	temp = np.zeros([irow, icol], dtype=np.uint8)
	trhalf = int(np.floor(trow/2))
	tchalf = int(np.floor(tcol/2))
	for x in range(trhalf, icol - trhalf + 1):
		for y in range(tchalf, irow - tchalf + 1):
			sumim = 0
			for iwin in range(trow):
				for jwin in range(tcol):
					sumim += img[y + jwin - trhalf - 1][x + iwin - trhalf - 1] * template[jwin][iwin]
					# print(sumim)
			temp[y][x] = sumim
			# print(temp[y][x])
	# print(temp[234][213])
	return histogram_normalization(temp)
	# return temp

def average(img, winsize):
	[row, col] = get_size(img)
	temp = np.zeros([row, col], dtype = np.uint8)
	half = np.int(np.floor(winsize/2))
	winarea = winsize * winsize
	for x in range(half, col - half):
		for y in range(half, row - half):
			sumim = img[y-half:y+winsize-half, x-half:x+winsize-half].sum()
			# print(sumim)
			temp[y][x] = np.int(np.floor(sumim/winarea))
	return temp

def gaussian_operator(img, winsize, sigma):
	def gaussian_template(winsize, sigma):
		template = np.zeros([winsize, winsize])
		center = np.int(np.floor(winsize/2)) + 1
		sumim = 0
		for i in range(winsize):
			for j in range(winsize):
				template[j][i] = np.exp(-((j-center)**2 + (i-center)**2)/(2*(sigma**2)))
				sumim += template[j][i]
		return template / sumim
	template = gaussian_template(winsize, sigma)
	return convolve(img, template)

def get_med(matrix):
	size = matrix.size
	mid = np.int(np.floor(size/2) + 1)
	reshaped = matrix.reshape(1, size)
	return np.sort(reshaped[0])[mid]


def medium_operator(img, winsize):
	[row, col] = get_size(img)
	winarea = winsize ** 2
	half = np.int(np.floor(winsize/2))
	temp = np.zeros([row, col], dtype = np.uint8)
	for x in range(half, col - half):
		for y in range(half, row - half):
			med = get_med(img[y-half:y+winsize-half, x-half:x+winsize-half])
			temp[y][x] = med
	return temp

def time_medium_operator(*args):
	[row, col] = list(args[0].shape)[:2]
	count = len(args)
	temp = np.zeros([row, col], dtype = np.uint8)
	for x in range(row):
		for y in range(col):
			sumim = 0
			for img in args:
				sumim += img[x][y]
			temp[x][y] = np.int(np.floor(sumim / count))
	return temp

def trun_med_operator(img, winsize):
	[row, col] = get_size(img)
	temp = np.zeros([row, col], dtype = np.uint8)
	half = np.int(np.floor(winsize / 2))
	for x in range(half, col - half - 1):
		for y in range(half, row - half - 1):
			# print(x, y)
			win = copy.deepcopy(img[y-half:y+half+1, x-half:x+half+1])
			# print(win)
			med = get_med(win)
			avg = win.mean()
			upper = 2 * med - win.min()
			lower = 2 * med - win.max()
			trunlist = []
			for i in range(winsize):
				for j in range(winsize):
					if win[j, i] < upper and med < avg:
						trunlist.append(win[j, i])
					if win[j, i] > lower and med > avg:
						trunlist.append(win[j, i])
			trunlist.sort()
			trunlen = len(trunlist)
			if trunlen > 0:
				if trunlen % 2 == 0:
					nhalf = np.int(trunlen / 2)
					temp[y, x] = np.int(np.floor(trunlist[nhalf]/2 + trunlist[nhalf-1]/2))
				else:
					temp[y, x] = trunlist[np.int(np.floor(trunlen / 2))]
			else:
				temp[y, x] = med
	return temp

def anisotropic_diffusion_operator(img):
	img = np.float32(img)
	k = 5	
	kk = k * k
	lambdaimg = 0.25
	iter_num = 20
	[row, col] = get_size(img)
	temp = np.zeros([row, col], dtype = np.uint8)
	for i in range(iter_num):
		for x in range(1, row - 1):
			for y in range(1, col - 1):
				Ei = img[x - 1, y] - img[x, y]
				Wi = img[x + 1, y] - img[x, y]
				Ni = img[x, y - 1] - img[x, y]
				Si = img[x, y + 1] - img[x, y]
				cN = np.exp((-Ni ** 2)/kk)
				cS = np.exp((-Si ** 2)/kk)
				cE = np.exp((-Ei ** 2)/kk)
				cW = np.exp((-Wi ** 2)/kk)
				temp[x, y] = np.uint8(img[x, y] + lambdaimg * (cN*Ni + cS*Si + cE*Ei + cW*Wi))
		img = temp
	return img



if __name__ == '__main__':
	img = cv2.imread('../pics/ad.jpg', 0)
	# print(img)
	cv2.imshow('img', img)

# '''
# 	histogram
# '''
	# start1 = time.time()
	# hist1 = histogram1(img)
	# # end1 = time.time()
	# start2 = time.time()
	# hist2 = histogram(img)
	# end2 = time.time()
	# # print('time1', end1-start1)
	# print('time2', end2-start2)
	# print(hist1 - hist2)


# '''
# 	point operator
# '''
	# linear operator
	# func = lambda x : x + 10
	
	# sawtooth operator
	# func = lambda x: x % 100 + 100

	# logarithmic point operator
	# func = lambda x: 20 * np.log(1000 * x)
	# start1 = time.time()
	# img2 = point_operator1(img, func)
	# end1 = time.time()
	# start2 = time.time()
	# img3 = point_operator(img, func)
	# print(img3)
	# end2 = time.time()
	# print('time1', end1 - start1)
	# print('time2', end2 - start2)


# '''
# 	# normalization
# '''
	# start1 = time.time()
	# img2 = histogram_normalization1(img)
	# end1 = time.time()
	# start2 = time.time()
	# img3 = histogram_normalization(img)
	# end2 = time.time()
	# print('time1', end1 - start1)
	# print('time2', end2 - start2)
	# histogram(img2)

# '''
	# equalization
# '''
	start1 = time.time()
	img2 = histogram_equalization1(img)
	end1 = time.time()
	start2 = time.time()
	img3 = histogram_equalization(img)
	end2 = time.time()
	print('time1', end1 - start1)
	print('time2', end2 - start2)
	

	# uniformed_thresholding
	# img2 = uniformed_thresholding(img, threshold = 150)

	# Otsu_thresholding
	# img = cv2.imread('../pics/1.jpg', 0)
	# cv2.imshow('img', img)
	# img2, threshold = ostu_thresholding(img)
	# print(threshold)
	
	# Convolve
	# template = np.array([[1/9, 1/9, 1/9], [1/9, 1/9, 1/9], [1/9, 1/9, 1/9]])
	# img2 = convolve(img, template)
	# # np.save('../pics/ad_matrix.npy', img2)
	# # img3 = np.load('../pics/ad_matrix.npy')
	# cv2.imwrite('../pics/ad_handled.jpg', img2)
	# img3 = cv2.imread('../pics/ad_handled.jpg', 0)
	# # img3 = [[float(row[i]) for i in range(len(row))] ]
	# # cv2.imshow('img3', img3)
	
	# # average
	# winsize = 15
	# img2 = average(img, winsize)

	# # gaussian operator
	# winsize = 5
	# sigma = 1.0
	# img2 = gaussian_operator(img, winsize, sigma)

	# # medium operator
	# winsize = 3
	# img2 = medium_operator(img, winsize)

	# time medium operator
	# img2 = time_medium_operator(img, img, img)

	# trun-med operator
	# img2 = trun_med_operator(img, winsize = 13)

	# anisotropic_diffusion_operator
	# img2 = anisotropic_diffusion_operator(img)
	
	cv2.imshow('img2', img2)
	cv2.imshow('img3', img3)
	k = cv2.waitKey(0)
	if k == 27:
		cv2.destroyAllWindows()
