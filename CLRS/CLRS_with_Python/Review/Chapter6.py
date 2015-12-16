#Review of Chapter6
#15.8.4
import math

class heap:
    def __init__(self, capacity, elem):
        self.capacity = capacity
        self.size = len(elem) - 1
        self.elem = elem
    
    def parent(self, i):
        return math.floor(i/2)

    def left(self, i):
        return 2*i+1

    def right(self, i):
        return 2*i+2

    def max_heapify(self, i):
        l = self.left(i)
        r = self.right(i)
        largest = i
        if l <= self.capacity and self.elem[l] > self.elem[i]:
            largest = l
        if r <= self.capacity and self.elem[r] > self.elem[largest]:
            largest = r
        if largest != i:
            self.elem[i], self.elem[largest] = self.elem[largest], self.elem[i]
            self.max_heapify(largest)
    
    #def min_heapify(self, i):
    #    l = left(i)
    #    r = right(i)
    #    minimum = i
    #    if l <= self.capacity and self.elem[l] < self.elem[i]:
    #        minimum = l
    #    if r <= self.capacity and self.elem[r] < self.elem[minimum]:
    #        minimum = r
    #    if minimum != i:
    #        self.elem[i], self.elem[minimum] = self.elem[minimum], self.elem[i]
    #        min_heapify(self, minimum)

    def build_max_heap(self):
        self.capacity = self.size
        for i in range(math.floor(self.capacity/2), -1, -1):
            self.max_heapify(i)

    #def build_min_heap(self):
    #    self.capacity = self.size
    #    for i in range(math.floor(self.capacity/2), 0, -1):
    #        min_heapify(self, i)

    def push(self, item):
        if self.size == self.capacity:
            return 'ERROR: THE HEAP IS FULL'
        self.size += 1
        self.elem.append(item)
        self.build_max_heap(self)

    def pop(self):
        self.elem.pop[0]
        self.size -= 1
        self.build_max_heap(self)

    def heapsort(self):
        self.build_max_heap()
        for i in range(self.size, -1, -1):
            self.elem[0], self.elem[self.size] = self.elem[self.size], self.elem[0]
            self.size -= 1
            self.max_heapify(0)
        return self.elem

# capacity = 100
# elem = [1,3,6,1,2,5,8,9]
# h = heap(capacity, elem)
# print(h.heapsort())

class priority_queue(heap):
    #用最大堆实现最大优先队列
    def maxmium(self):
        self.build_max_heap()
        return self.elem[0]

    def extract_maxmium(self):
        self.build_max_heap()
        if self.size < 1:
            return "ERROR: QUEUE OVERFLOW"
        maxmium = self.elem[0]
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

# capacity = 100
# elem = [1,3,6,1,2,5,8,9]
# myQueue = priority_queue(capacity, elem)
# print(myQueue.maxmium())
# print(myQueue.extract_maxmium())
# myQueue.insert(23)
# print(myQueue.maxmium())
# myQueue.increase_key(2,100)
# print(myQueue.maxmium())
