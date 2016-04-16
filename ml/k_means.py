import numpy as np
import random
from matplotlib import pyplot as plt

class kmeans:
	'''
	The class of k-means Al.
	'''
	def __init__(self, A, n = 2, maxiter = 10):
		'''
		A is a Data Matrix with a type of np.ndarray,
		in which each line is a data point of n-dimension.

		The last number in each line is the type of the point.

		n is the number of centers
		'''
		self.A = A
		self.n = n
		[self.row, self.col] = self._get_size()
		self.col -= 1
		self.centers = self._init_centers()
		# print(self.centers)
		'''
		self.row is also the number of points,
		and self.col is the dimension of points + type,
		when the class is inited, the type should be set 
		as -1;
		'''
		self.maxiter = maxiter

	def _get_size(self):
		return list(self.A.shape)[:2]

	def _init_centers(self):
		indexlist = [random.randint(0, self.row-1) for i in range(self.n)]
		for i in range(self.n):
			self.A[indexlist[i], -1] = i
		return [self.A[i] for i in indexlist]

	def _iter(self):
		self._determine_types()
		self._refresh_centers()

	def _determine_types(self):
		for i in range(self.row):
			dist_list = []
			for j in self.centers:
				dist_list.append(self._get_distance(self.A[i, 0], j[0]))
			key = self._get_min_dis(dist_list)
			self.A[i, -1] = self.centers[key][-1]

	def _get_distance(self, a, b):
		return np.sqrt(sum((a-b)**2))

	def _get_min_dis(self, dist_list):
		flag = dist_list[0]
		key = 0
		for i in range(len(dist_list)):
			if dist_list[i] < flag:
				key = i
				flag = dist_list[i]
		return key

	def _refresh_centers(self):
		self.data_by_center = [[] for i in range(self.n)]
		for data in self.A:
			center_type = data[-1]
			self.data_by_center[center_type].append(data)
		self.centers = [list(sum(self.data_by_center[i])/len(self.data_by_center[i])) \
			for i in range(len(self.data_by_center))]
		for i in range(self.n):
			self.centers[i][-1] = int(self.centers[i][-1])

	def run(self):
		for i in range(self.maxiter):
			self._iter()

	def plot(self):
		data_x = []
		data_y = []
		z = []
		for i in range(len(self.data_by_center)):
			data = self.data_by_center[i]
			for point in data:
				data_x.append(point[0][0])
				data_y.append(point[0][1])
				z.append(i/self.n)
		sc = plt.scatter(data_x, data_y, c=z, vmin=0, vmax=1, s=35, alpha=0.8)
		plt.colorbar(sc)
		plt.show()


if __name__ == '__main__':
	m = 100
	A = np.random.random([m, 2])
	A = np.asarray([[data, 0] for data in A])
	k = kmeans(A, n=3)
	k.run()
	# print(k.data_by_center)
	k.plot()




















