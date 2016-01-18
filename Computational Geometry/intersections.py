# find_intersection
from data_structure import AVLTree, Event_Queue

class point:
	"""
	the class of points
	"""
	def __init__(self, x, y):
		self.x = x
		self.y = y

class Line_segment:
	"""
	the class of line segments, in which start_point and end_point are points.
	meanwhile, start_point means the upper endpoint and end_point means the lower endpoint,
	and the key of a line segment is its start_point
	"""
	def __init__(self, start_point, end_point):
		self.start = start_point
		self.end = end_point
		self.key = self.start
		
def find_intersection(S):
	'''
	input: a list of line segments, elements in which are type of Line_segments.
	output: a list of intersection points among the segments in S, with for each 
			intersection point the segments that contain it.
	Using Plane Sweep Algorithm
	'''
	q = Event_Queue()
	for segment in S:
		q.push(segment)
	J = AVLTree()
	while len(q) >= 1:
		next_event_point = q.pop()
		handle_event_point(p)

def 


