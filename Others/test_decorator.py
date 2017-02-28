import time
from functools import wraps, partial
from inspect import signature
import logging

def timeit(func):
	@wraps(func)
	def wrapper(*args, **kwargs):
		start = time.time()
		result = func(*args, **kwargs)
		end = time.time()
		print(func.__name__, end-start)
		return result
	return wrapper

def print_res(func):
	@wraps(func)
	def wrapper(*args, **kwargs):
		result = func(*args, **kwargs)
		print(func.__name__, result)
		return result
	return wrapper

def logged(level, name = None, message = None):
	'''
	Logging
	'''
	def decorate(func):
		logname = name if name else func.__module__
		log = logging.getLogger(logname)
		logmsg = message if message else func.__name__

		@wraps(func)
		def wrapper(*args, **kwargs):
			log.log(level, logmsg)
			return func(*args, **kwargs)
		return wrapper
	return decorate

@timeit
@print_res
@logged(logging.CRITICAL)
def countdown(n:int) -> int:
	'''
	countdown from n
	'''
	while n > 0:
		n -= 1


origin_countdown = countdown.__wrapped__

class P:
	name = property()

	@name.getter
	def name(self):
		return self._name

	@name.setter
	def name(self, value):
		if not isinstance(value, str):
			raise TypeError('Expected a string')
		self._name = value

	@classmethod
	def name(cls, func):
		# @wraps(func)
		pass



if __name__ == '__main__':
	# countdown(100)
	# print(countdown.__name__, countdown.__doc__, countdown.__annotations__)
	# countdown.__wrapped__(10000)
	# print(signature(countdown))
	# origin_countdown(1000)
	a = P
	a.name = 2
	print(a.name)