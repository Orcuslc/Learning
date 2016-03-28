# Convolution Neural Network
import numpy as np

def get_size(img):
	return list(img.shape)[:2]

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
		self.datalist = [data]
		self.maxiter = maxiter
		self.lam = lam


	def _init_weight(self, weight_size_list):
		weightlist = []
		for index in range(len(weight_size_list)-1):
			weightlist.append(np.random.randn(weight_size_list[index], weight_size_list[index+1]))
		self.weightlist = weightlist

	def _proporgate(self, index):
		func = np.vectorize(self.funclist[index])
		newdata = func(np.dot(self.datalist[index], self.weightlist[index]))
		self.datalist.append(newdata)

	def _bp(self, error, index):
		delta = np.dot(np.transpose(self.datalist[index-1]), error * dfunclist[index-1](self.datalist[index]))
		self.weightlist[index] *= (1-self.lam)
		self.weightlist[index] -= delta * self.step
		self._error = np.dot(np.transpose(self.weightlist[index-1]), error * dfunclist[index-1](self.datalist[index-1]))

	def _thresholding(self):
		result = self.datalist[-1]
		maxpos = result.argmax(1)
		for index in range(len(maxpos)):
			result[index, :] = 0
			result[index, maxpos[index]] = 1
		self.datalist.append(result)

	def _iter(self):
		for i in range(self.N - 1):
			self._proporgate(i)
		self._thresholding()
		self._error = self.catagory - self.datalist[-1]
		for i in range(self.N-2, -1, -1):
			self._bp(self._error, i)

	def run(self):
		for i in range(self.maxiter):
			self._iter()

if __name__ == '__main__':
	data = [[0.01*i, 0.01*j] for i in range(101) for j in range(101)]
	f = lambda x1, x2: 0 if x1 ** 2 + x2 ** 2 - 1/4 < 0 else 1
	catagory = [[0, 1] if f(x[0], x[1]) == 0 else [1, 0] for x in data]
	funclist = [lambda x: 1/(1+np.exp(-x)) for i in range(2)]
	dfunclist = [lambda x: x*(1-x) for i in range(2)]
	weight_size_list = [2, 5, 2]
	n = NN(data, catagory, weight_size_list, funclist, dfunclist)
	n.run()
	
# class CNN(NN):
# 	def __init__(self, data, ):
# 		'''
# 		The data for init is used for training, which is a numpy.array
# 		'''