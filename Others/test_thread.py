from threading import Thread, Event, Semaphore
import time

def countdown(n, started_event):
	print('countdown starting')
	started_event.set()
	while n:
		print('T-minus', n)
		n -= 1
		time.sleep(0.1)
	print('countdown ended')

def test1():
	started_event = Event()

	print('Launching countdown')
	t = Thread(target = countdown, args = (10, started_event))
	t.start()

	started_event.wait()
	for i in range(10):
		print('countdown is running', i)

def worker(n, sema):
	sema.release()
	sema.acquire()
	print('Working', n)

def test2():
	sema = Semaphore(0)
	nworkers = 10
	for n in range(nworkers):
		t = Thread(target = worker, args = (n, sema,))
		t.start()


