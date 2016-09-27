class GPACalculator:
	def __init__(self):
		self.credit = 0
		self.count = 0

	def add_course(self, credit, grade):
		self.credit += credit
		self.count += credit*grade

	def calc_gpa(self):
		return self.count/self.credit

