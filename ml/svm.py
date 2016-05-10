# Support Vector Machine
import numpy as np
import matplotlib.pyplot as plt

class naive_SVM:
	def __init__(self, A):
		'''
		A is a Data Matrix with a type of np.ndarray,
		in which each line is a data point of n-dimension.
		'''
		self.A = np.asarray()
		self.support_vector = []