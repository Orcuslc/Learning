#Exercise 6-2
#15.8.5
import math

class d_array_heap(object):
	def __init__(self, d, capacity, elem):
		self.d = d
		self.capacity = capacity
		self.size = len(elem) - 1
		self.elem = elem

	def parent(self, i):
		return math.floor((i - 1)/self.d)

	def child(self, i, j):
		return i * self.d + j

	def max_heapify(self, i):
		maxmium = i
		for j in range(self.d):
			achild = child(i, j)
			if achild < self.size and self.elem[achild] > self.elem[maxmium]:
				maxmium = achild
		if i != maxmium:
			self.elem[i], self.elem[maxmium] = self.elem[maxmium], self.elem[i]
			max_heapify(maxmium)
	
	def build_max_heap(self):
		self.capacity = self.size
		for i in range(math.floor(self.capacity/self.d), -1, -1):
		self.max_heapify(i)

class d_array_priority_queue(d_array_heap):
	
	def maxmium(self):
		self.build_max_heap()
		return self.elem[0]

	def extract_maxmium(self):
		self.build_max_heap()
		if self.size < 1:
			return "ERROR: QUEUE OVERFLOW"
		maxmium = maxmium()
		self.elem[0] = self.elem[self.size]
		self.size -= 1
		self.max_heapify(0)
		return maxmium

	def increase_key(self, i, key):
        self.build_max_heap()
        if key < self.elem[i]:
            return "ERROR: NEW KEY IS SMALLER THAN CURRENT KEY"
        self.elem[i] = key
        while i > 0 and self.elem[self.parent(i)] < self.elem[i]:
            self.elem[self.parent(i)], self.elem[i] = self.elem[i], self.elem[self.parent(i)]
            i = self.parent(i)

    def insert(self, key):
        self.build_max_heap()
        self.size += 1
        self.elem[self.size] = float('-inf')
        self.increase_key(self.size, key)

 