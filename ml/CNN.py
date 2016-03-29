# Convolution Neural Network
import numpy as np
from copy import deepcopy
from sklearn import preprocessing
def get_size(img):
	return list(img.shape)[:2]

def normalize(m):
	row_sums = m.sum(axis = 1)
	return m / row_sums[:, np.newaxis]

class NN:
	'''
	N-layer Neural Network
	'''
	def __init__(self, data, catagory, weight_size_list, funclist, dfunclist, step = 0.1, lam = 0.1, maxiter = 10):
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
		self.init_data = data
		self.datalist = [data]
		self.maxiter = maxiter
		self.lam = lam
		self.p = 0

	def _init_weight(self, weight_size_list):
		weightlist = []
		for index in range(len(weight_size_list)-1):
			weightlist.append(np.random.randn(weight_size_list[index], weight_size_list[index+1]))
		self.weightlist = weightlist

	def _proporgate(self, index):
		func = np.vectorize(self.funclist[index])
		newdata = func(np.dot(self.datalist[index], self.weightlist[index]))
		# a = preprocessing.MinMaxScaler()
		# newdata = a.fit_transform(newdata)
		self.datalist.append(newdata)

	def _calct(self, index):
		eps = 0.1
		w = deepcopy(self.weightlist[index])
		t = deepcopy(w)
		[row, col] = get_size(t)
		def cal(w, i, j):
			w[i, j] += eps
			cost1 = self._cost(index, w)
			w[i, j] -= (2*eps)
			cost2 = self._cost(index, w)
			return (cost2 - cost1) / (2*eps)
		for i in range(row):
			for j in range(col):
				t[i, j] = cal(w, i, j)
		# print(t)

	def _cost(self, index, w):
		func = np.vectorize(self.funclist[index])
		newdata = func(np.dot(self.datalist[index], w))
		for i in range(index + 1, self.N - 1):
			newdata = func(np.dot(newdata, self.weightlist[i]))
		result = newdata
		maxpos = result.argmax(1)
		for index in range(len(maxpos)):
			result[index, :] = 0
			result[index, maxpos[index]] = 1
		cost = np.abs(result - self.catagory).sum()
		return cost

	def _bp(self, index):
		# print(self._error)
		# print(self.dfunclist[index-1](self.datalist[index]))
		# print(self._error * self.dfunclist[index-1](self.datalist[index]))
		delta = np.dot(np.transpose(self.datalist[index-1]), self._error * self.dfunclist[index-1](self.datalist[index]))
		self.weightlist[index-1] *= (1-self.lam)
		self.weightlist[index-1] += delta * self.step
		self._error = np.dot(self._error * self.dfunclist[index-1](self.datalist[index]) , np.transpose(self.weightlist[index-1]))

	def _thresholding(self):
		result = deepcopy(self.datalist[-1])
		maxpos = result.argmax(1)
		for index in range(len(maxpos)):
			result[index, :] = 0
			result[index, maxpos[index]] = 1
		self.datalist.append(result)  

	def _iter(self):
		for i in range(self.N - 1):
			self._proporgate(i)
		# self._calct(1)
		self._thresholding()
		self._error = self.catagory - self.datalist[-1]
		for i in range(self.N-1, 0, -1):
			self._bp(i)
		self.datalist = [self.init_data]

	def _evaluate(self):
		self.p = np.abs(self._error).sum()
		print(self.p)

	def train(self):
		for i in range(self.maxiter):
			self._iter()
			self._evaluate()
		for i in range(self.N - 1):
			self._proporgate(i)
		self._thresholding()

	# def run(self, data):
	# 	self.
	# 	for i in range(self.N):
	# 		self._proporgate()

if __name__ == '__main__':
	data = np.asarray([[0.01*i, 0.01*j] for i in range(101) for j in range(101)])
	f = lambda x1, x2: 0 if x1 ** 2 + x2 ** 2 - 1/4 < 0 else 1
	catagory = np.asarray([[0, 1] if f(x[0], x[1]) == 0 else [1, 0] for x in data])
	funclist = [lambda x: 1/(1+np.exp(-x)) for i in range(3)]
	dfunclist = [lambda x: x*(1-x) for i in range(3)]
	weight_size_list = [2, 3, 2]
	n = NN(data, catagory, weight_size_list, funclist, dfunclist)
	n.train()

	
# class CNN(NN):
# 	def __init__(self, data, ):
# 		'''
# 		The data for init is used for training, which is a numpy.array
# 		'''