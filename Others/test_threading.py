from queue import Queue
from threading import Thread, Event, local
import time
from contextlib import contextmanager

i = 0

def produce_data():
	global i
	i += 1
	return i

def producer(outq):
	while i < 10:
		event = Event()
		outq.put((produce_data(), event))
		time.sleep(0.2)
		event.wait()

def consumer(inq):
	while True:
		data, event = inq.get()
		print(data)
		time.sleep(1)
		event.set()

def test():
	q = Queue()
	t1 = Thread(target = consumer, args = (q,))
	t2 = Thread(target = producer, args = (q,))
	t1.start()
	t2.start()
	q.join()
# test()

_local = local()
@contextmanager
def acquire(*locks):
	locks = sorted(locks, key = lambda x: id(x))
	acquire = getattr(_local, 'acquired', [])
	