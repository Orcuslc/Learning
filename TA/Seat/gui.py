from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from seats import *
import sys
import csv
from O365 import Message
import os

class Window(QMainWindow):
	def __init__(self):
		super().__init__()
		self._seat_file_name = None
		self._hawkid = None
		self._passwd = None
		self._course = None
		self._exam = None
		self._time = None
		self.initUI()

	def _centerlize(self):
		qr = self.frameGeometry()
		cp = QDesktopWidget().availableGeometry().center()
		qr.moveCenter(cp)
		self.move(qr.topLeft())

	def _get_hawkid(self):
		hawkid, ok = QInputDialog.getText(self, 'Seats', 'Enter Hawk ID:')
		if ok:
			self._hawkid = hawkid
			self._enter_hawkid_edit.setText(hawkid)

	def _get_passwd(self):
		passwd, ok = QInputDialog.getText(self, 'Seats', 'Enter Password:')
		if ok:
			self._passwd = passwd
			self._enter_passwd_edit.setText('*'*len(passwd))

	def _get_seat_file_name(self):
		self._seat_file_name = QFileDialog.getOpenFileName(self, 'Open file', './')[0]
		if self._seat_file_name:
			self._choose_seat_file_edit.setText(self._seat_file_name)

	def _get_course(self):
		course, ok = QInputDialog.getText(self, 'Seats', 'Enter Course:')
		if ok:
			self._course = course
			self._enter_course_edit.setText(course)

	def _get_exam(self):
		exam, ok = QInputDialog.getText(self, 'Seats', 'Enter Exam:')
		if ok:
			self._exam = exam
			self._enter_exam_edit.setText(exam)

	def _get_time(self):
		time, ok = QInputDialog.getText(self, 'Seats', 'Enter Time:')
		if ok:
			self._time = time
			self._enter_time_edit.setText(time)

	def _quit(self):
		self._sign = 0

	def initUI(self):
		choose_seat_file_button = QPushButton('Choose Seat File', self)
		choose_seat_file_button.clicked.connect(self._get_seat_file_name)
		self._choose_seat_file_edit = QLineEdit()

		enter_hawkid_button = QPushButton('Enter Hawk ID', self)
		enter_hawkid_button.clicked.connect(self._get_hawkid)
		self._enter_hawkid_edit = QLineEdit(self)

		enter_passwd_button = QPushButton('Enter Password', self)
		enter_passwd_button.clicked.connect(self._get_passwd)
		self._enter_passwd_edit = QLineEdit(self)

		enter_course_button = QPushButton('Enter Course', self)
		enter_course_button.clicked.connect(self._get_course)
		self._enter_course_edit = QLineEdit(self)

		enter_exam_button = QPushButton('Enter Exam', self)
		enter_exam_button.clicked.connect(self._get_exam)
		self._enter_exam_edit = QLineEdit(self)

		enter_time_button = QPushButton('Enter Time', self)
		enter_time_button.clicked.connect(self._get_time)
		self._enter_time_edit = QLineEdit(self)

		send_button = QPushButton('Send', self)
		send_button.clicked.connect(self.run)
		cancel_button = QPushButton('Cancel', self)
		cancel_button.clicked.connect(self._quit)

		self._status_edit = QTextEdit(self)

		grid = QGridLayout()
		grid.setSpacing(10)
		grid.addWidget(choose_seat_file_button, 3, 0)
		grid.addWidget(self._choose_seat_file_edit, 3, 1, 1, 5)
		grid.addWidget(enter_hawkid_button, 1, 0)
		grid.addWidget(self._enter_hawkid_edit, 1, 1)
		grid.addWidget(enter_passwd_button, 1, 2)
		grid.addWidget(self._enter_passwd_edit, 1, 3)
		grid.addWidget(enter_course_button, 2, 0)
		grid.addWidget(self._enter_course_edit, 2, 1)
		grid.addWidget(enter_exam_button, 2, 2)
		grid.addWidget(self._enter_exam_edit, 2, 3)
		grid.addWidget(enter_time_button, 2, 4)
		grid.addWidget(self._enter_time_edit, 2, 5)
		grid.addWidget(send_button, 5, 4)
		grid.addWidget(cancel_button, 5, 5)
		grid.addWidget(self._status_edit, 6, 0, 6, 6)

		wid = QWidget(self)
		self.setCentralWidget(wid)
		wid.setLayout(grid)
		# self.resize(800, 600)
		self._centerlize()
		self.setWindowTitle('Seats')
		self.show()

	def _parse(self, row):
		[name, hawkid, seat] = row
		email = hawkid + "@iowa.uiowa.edu"
		seat = seat.split(' ')
		seat.remove('')
		seat[0], seat[1] = seat[1], seat[0]
		exam = self._course + " " + self._exam
		title = exam + " Seat: " + '-'.join(seat)
		content = "Dear " + name + ":\n\n" + "Your seat for " + exam + " is: " + "Building " + seat[0] + ", Room " + seat[1] + ", and Seat " + seat[2] + ". It is recommended that you explore your seat a day before the exam.\n" + "The Exam is on " + self._time
		return [name, email, title, content]

	def _send(self, msg, name, email, title, content):
		msg.setRecipients(email)
		msg.setSubject(title)
		msg.setBody(content)
		msg.sendMessage()

	def run(self):
		self._sign = 1
		if not self._seat_file_name or not self._hawkid or not self._passwd or not self._course or not self._exam or not self._time:
			self._status_edit.setText("Error: Missing Items")
			return
		with open(self._seat_file_name) as f:
			m = Message(auth = (self._hawkid+"@uiowa.edu", self._passwd))
			data = csv.reader(f)
			count = 0
			for row in data:
				if(self._sign == 0):
					break
				count += 1
				[name, email, title, content] = self._parse(row)
				self._send(m, name, email, title, content)
				self._status_edit.append(str(count) + " " + name + " Sent!\n")
				QCoreApplication.processEvents()
			f.close()

if __name__ == '__main__':
	app = QApplication(sys.argv)
	ex = Window()
	sys.exit(app.exec_())