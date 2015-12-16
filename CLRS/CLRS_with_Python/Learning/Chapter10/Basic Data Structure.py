#Basic Data Structure
#15.7.26

class Stack:
	#用list模拟stack
	def __init__(self):
		self.items = []

	def is_empty(self):
		return len(self.items) == 0

	def push(self, item):
		self.items.append(item)

	def pop(self):
		return self.items.pop()
		
'''
s = Stack()
print(s.is_empty())
s.push(1)
s.push('das')
s.push('scs')
print(s.is_empty())
print(s.pop())
'''

class Queue:
	#用list模拟queue
	def __init__(self):
		self.items = []

	def enqueue(self, x):
		self.items.append(x)

	def dequeue(self):
		key = self.items[0]
		for index in range(1, len(self.items)):
			self.items[index - 1] = self.items[index]
		del(self.items[-1])
		return key
'''
q = Queue()
q.enqueue(1)
q.enqueue(2)
print(list(q.items))
print(q.dequeue())
print(q.items)
'''

# class myQueue:
# 	#用两个栈实现队列
# 	def __init__(self, A, B):
# 		self.items = A.items

# 	def enqueue(self, x, Stack A):
# 		A.push()

# 	def dequeue(self,Stack S1,Stack B):
# 		if len(B.items) != 0:
# 			B.pop()
# 		else:
# 			for index in range(len(A) - 1, -1, -1):
# 				B.items.append(A.items[index])
# 			B.pop()
'''			
A = Stack()
B = Stack()
q = myQueue(A, B)
q.enqueue(1, A)
q.enqueue(2)
print(q.items)
q.dequeue()
print(q.items)

'''

class Node(object):
	def __init__(self, val, p = 0):
		self.data = val
		self.next = p
		self.prev = p

class Linklist(object):
	def __init__(self):
		self.head = 0

	def __getitem__(self, key):
		if self.is_empty():
			print('Linklist is empty')
			return
		elif key < 0 or key > self.getlength():
			print('Key Error')
			return
		else:
			return self.getitem(key)

	def __setitem__(self, key, value):
		if self.is_empty():
			print('Linklist is empty')
			return

		elif key < 0 or key > self.getlength():
			print('Key Error')
			return

		else:
			self.delete(key)
			return self.insert(key)

	def initlist(self, data):
		self.head = Node(data[0])
		p = self.head
		for i in data[1:]:
			node = Node(i)
			p.next = node
			npde.prev = p
			p = p.next

		def getlength(self):
			p = self.head()
			length = 0
			while p != 0:
				length += 1
				p = p.next
			return length

		def is_empty(self):
			if self.getlength() == 0:
				return True
			else:
				return False

		def clear(self):
			self.head = 0

		def append(self, item):
			q = Node(item)
			if self.head == 0:
				self.head = q
			else:
				p = self.head
				while p.next != 0:
					p = p.next
				p.next = q
				q.prev = p

		def getitem(self, index):
			if self.is_empty():
				print('Linklist is empty')
				return
			j = 0
			p = self.head

			while p.next != 0 and j < index:
				p = p.next
				j += 1
			if j == index:
				return p.data
			else:
				print('target not exist')

		def insert(self, index, item):
			if self.is_empty() or index < 0 or index > self.getlength():
				print('Linklist is empty')
				return
			if index == 0:
				q = Node(item, self.head)
				self.head = q
			p = self.head
			post = self.head
			j = 0
			while p.next != 0 and j < index:
				post = p 
				p = p.next
				j += 1 
			if index == j:
				q = Node(item, p)
				post.next = q
				q.prev = post
				q.next = p 
				p.prev = q

		def delete(self, index):
			if self.is_empty() or index < 0 or index > self.getlength():
				print('Linklist is empty')
				return
			if index == 0:
				q = Node(item, self.head)
				self.head = q
			p = self.head
			post = self.head 
			j = 0
			while p.next != 0 and j < index:
				post = p 
				p = p.next
				j += 1 
			if index == j:
			 	post.next = p.next
			 	p.next.prev = post

		def index(self, value):
			if self.is_empty():
			 	print('Linklist is empty')
			 	return

			p = self.head
			i = 0
			while p.next != 0 and not p.data == value:
				p = p.next
				i += 1
			if p.data == value:
			 	return i
			else:
			 	return -1 

