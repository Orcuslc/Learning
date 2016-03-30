import numpy as np 
from copy import deepcopy

def get_size(m):
	return list(m.shape)[:2]

def normalize(m):
	row_sums = m.sum(axis=1)
	return m/row_sums[:, np.newaxis]

class NN:
	"""
	N-layer NN
	"""
	def __init__(self, data, catagory, weight_size, funclist, dfunclist, step=0.5, lam=0.1, maxiter=10):
		self.data = data
		self.catagory = catagory
		self._error = 0
		self.step = step
		self.funclist = funclist
		self.dfunclist = dfunclist
		self.weightlist = None
		self._init_weight(weight_size)
		self.N = len(weight_size)
		self.init_data = deepcopy(data)
		self.datalist
