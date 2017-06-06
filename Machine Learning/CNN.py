# Convolution Neural Network
import numpy as np
from copy import deepcopy
# from sklearn import preprocessing
def get_size(img):
	return list(img.shape)[:2]

def normalize(m):
	row_sums = m.sum(axis = 1)
	return m / row_sums[:, np.newaxis]

def point_operator(w, func, *args):
	f = np.vectorize(func)
	return f(w, *args)

def equalize(m):
	shaped_m = m.reshape(1, m.size)
	maxim = shaped_m.max(1)[0]
	minim = shaped_m.min(1)[0]
	rangeim = maxim - minim
	normf = lambda x, minim, rangeim: (x - minim) / rangeim
	return point_operator(m, normf, minim, rangeim)

class NN:
	'''
	N-layer Neural Network
	'''
	def __init__(self, data, catagory, weight_size_list, funclist, dfunclist, path, step = 1, lam = 0.3, maxiter = 10, minerror = 1e-7):
		'''
		func in funclist is a function of x(i), and func in dfunclist 
		is a function of y(i), inwhich x(i) are inputs mutipled by weight,
		and y(i) is the result of f(x(i))
		'''
		self.data = data
		self.catagory = catagory
		self._error = 0
		self.error_matrix = None
		self.step = step
		self.funclist = funclist
		self.dfunclist = dfunclist
		self.N = len(weight_size_list)
		self.weightlist = None
		self._init_weight(weight_size_list)
		self.result = None
		self.init_data = deepcopy(data)
		self.datalist = [data]
		self.maxiter = maxiter
		self.lam = lam
		self.p = 0
		self.pp = 0
		self.minerror = minerror
		self.is_save = False
		self.path = path

	def _init_weight(self, weight_size_list):
		weightlist = []
		for index in range(len(weight_size_list)-1):
			weightlist.append(np.random.randn(weight_size_list[index], weight_size_list[index+1]))
		self.weightlist = [equalize(w) for w in weightlist]

	def _proporgate(self, index):
		func = np.vectorize(self.funclist[index])
		newdata = func(np.dot(self.datalist[-1], self.weightlist[index]))
		self.datalist.append(newdata)

	# def _calct(self, index):
	# 	eps = 0.1
	# 	w = deepcopy(self.weightlist[index])
	# 	t = deepcopy(w)
	# 	[row, col] = get_size(t)
	# 	def cal(w, i, j):
	# 		w[i, j] += eps
	# 		cost1 = self._cost(index, w)
	# 		w[i, j] -= (2*eps)
	# 		cost2 = self._cost(index, w)
	# 		return (cost2 - cost1) / (2*eps)
	# 	for i in range(row):
	# 		for j in range(col):
	# 			t[i, j] = cal(w, i, j)
	# 	print(t)

	# def _cost(self, index, w):
	# 	func = np.vectorize(self.funclist[index])
	# 	newdata = func(np.dot(self.datalist[index], w))
	# 	for i in range(index + 1, self.N - 1):
	# 		newdata = func(np.dot(newdata, self.weightlist[i]))
	# 	result = newdata
	# 	maxpos = result.argmax(1)
	# 	for index in range(len(maxpos)):
	# 		result[index, :] = 0
	# 		result[index, maxpos[index]] = 1
	# 	cost = np.abs(result - self.catagory).sum()
	# 	return cost

	def _bp(self, index):
 		delta = np.dot(np.transpose(self.datalist[index-1]), self._error * self.dfunclist[index-1](self.datalist[index]))
 		self.weightlist[index-1] += delta * self.step
 		self._error = np.dot(self._error * self.dfunclist[index-1](self.datalist[index]) , np.transpose(self.weightlist[index-1]))

	def _thresholding(self):
		result = deepcopy(self.datalist[-1])
		maxpos = result.argmax(1)
		for index in range(len(maxpos)):
			result[index, :] = 0
			result[index, maxpos[index]] = 1
		self.datalist.append(result)

	def _norm_thresholding(self):
		self.datalist[-1] = normalize(self.datalist[-1])
		# print(self.datalist[-1])

	def _iter(self):
		for i in range(self.N - 1):
			self._proporgate(i)
		self._norm_thresholding()
		self._error = (self.catagory - self.datalist[-1]) / list(self.datalist[0].shape)[0]
		self._evaluate()
		for i in range(self.N-1, 0, -1):
			self._bp(i)
		self.datalist = [self.init_data]

	def _evaluate(self):
		self.pp = self.p
		self.p = np.abs(self._error * self._error).sum() / 2
		print(self.p)

	def train(self):
		self.is_save = False
		for i in range(self.maxiter):
			print(i)
			self._iter()
			print('\n')
			if abs(self.pp - self.p) < self.minerror:
				break
		for i in range(self.N - 1):
			self._proporgate(i)
		self._norm_thresholding()
		self.save_to_path()

	def save_to_path(self):
		np.savez(self.path, tuple(self.weightlist))
		self.is_save = True

	def run(self, data, catagory):
		print(self.is_save)
		# if self.is_save == True:
		weightlist_tmp = np.load(self.path)
		# print(weightlist_tmp)
		self.weightlist = weightlist_tmp["arr_0"]
		# for i in range(self.N-1):
		# 	print(weightlist_tmp["arr_0"])
		# 	self.weightlist.append(weightlist_tmp["arr_%s"%i])

		# print(self.weightlist)
		self.datalist = [data]
		for i in range(self.N - 1):
			self._proporgate(i)
		self._thresholding()
		self._error = catagory - self.datalist[-1]
		self._evaluate()
		return self.datalist[-1], self.p
		# else:
		# 	raise ImportError('The weightlist is not trained yet')


class CNN(NN):
	def __init__(self, convlist, data, catagory, weight_size_list, funclist, dfunclist, path, step = 1, lam = 0.3, maxiter = 10, minerror = 1e-7):
		'''

		'''
		super().__init__(data, catagory, weight_size_list, 	funclist, dfunclist, path, step, lam, maxiter, minerror)


if __name__ == '__main__':
	m = 3
	data = np.asarray([[0.01*i, 0.01*j] for i in range(101) for j in range(101)])
	f = lambda x1, x2: 0 if x1 ** 2 + x2 ** 2 - 1/4 < 0 else 1
	catagory = np.asarray([[0, 1] if f(x[0], x[1]) == 0 else [1, 0] for x in data])
	funclist = [lambda x: 1/(1+np.exp(-x)) for i in range(m)]
	dfunclist = [lambda x: x*(1-x) for i in range(m)]
	weight_size_list = [2, 5, 7, 2]
	# # data = np.arctan(data) * 2/np.pi
	path = "NN_1.npz"
	n = NN(data, catagory, weight_size_list, funclist, dfunclist, maxiter=10000, minerror=1e-100, path=path)
	n.train()
	# data = np.asarray([[0.01, 0.02]])
	# cata = np.asarray([[0, 1]])
	# res, p = n.run(data, cata)
	# print(res, p)

	#test2
	# data = np.asarray([[0, 0], [0, 1], [1, 0], [1, 1]])
	# catagory = np.asarray([[1, 0], [0, 1], [0, 1], [1, 0]])
	# n = NN(data, catagory, weight_size_list, funclist, dfunclist, maxiter=10000)
	# n.train()

	# test = np.asarray([[0.98, 0.02]])
	# cata = np.asarray([[0, 1]])
	# r, e = n.run(test, cata)
	# print(r, e)

	
# class CNN(NN):
# 	def __init__(self, data, ):
# 		'''
# 		The data for init is used for training, which is a numpy.array
# 		'''