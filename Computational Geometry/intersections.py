# find_intersection
from data_structure import AVLTree, Event_Queue, Node
import random
import matplotlib.pyplot as plt

class point(Node):
	"""
	the class of points
	"""
	def __init__(self, x, y):
		super().__init__([y, x], [])
		self.x = x
		self.y = y


class Line_segment:
	"""
	the class of line segments, in which start_point and end_point are points.
	meanwhile, start_point means the upper endpoint and end_point means the lower endpoint,
	and the key of a line segment is its start_point
	"""
	def __init__(self, start_point, end_point):
		if start_point.y == end_point.y:
			if start_point.x <= end_point.x:
				upper = start_point
				lower = end_point
			else:
				upper = end_point
				lower = start_point
		elif start_point.y < end_point.y:
			upper = end_point
			lower = start_point
		else:
			upper = start_point
			lower = end_point
		self.upper = upper
		self.lower = lower
		self.data = [upper, lower]
		
def find_intersection(S):
	'''
	input: a list of line segments, elements in which are type of Line_segments.
	output: a list of intersection points among the segments in S, with for each 
			intersection point the segments that contain it.
	Using Plane Sweep Algorithm
	'''
	q = Event_Queue()
	for segment in S:
		upper = segment.upper
		lower = segment.lower
		upper.segment = segment.data
		lower.segment = []
		q.push(upper)
		q.push(lower)
	J = AVLTree()
	# q.traverse(lambda x: print(x.key))
	while len(q) >= 1:
		next_event_point = q.pop()
		handle_event_point(next_event_point)

	def handle_event_point(event_point):
		U_p = event_point.data
		

if __name__ == '__main__':
	n = 5 * 2
	x_list = [random.random() * 10 for i in range(n)]
	y_list = [random.random() * 10 for i in range(n)]
	points = [point(x_list[i], y_list[i]) for i in range(n)]
	line_segments = [Line_segment(points[i], points[i+1]) for i in range(int(n/2))]
	for seg in line_segments:
		plt.plot([seg.upper.x, seg.lower.x], [seg.upper.y, seg.lower.y], 'r')	
	plt.show()
	find_intersection(line_segments)



