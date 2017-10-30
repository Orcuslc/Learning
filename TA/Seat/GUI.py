from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
from PyQt5.QtCore import *
from seats import *
import sys
import csv
from O365 import Message
import os
import json

class Window(QMainWindow):
	def __init__(self):
		super().__init__()
		self._seat_file_name = None
		self._hawkid = None
		self._passwd = None
		self._course = None
		self._exam = None
		self._time = None
		self._title_state = False
		self._content_state = False
		self._title = None
		self._content = None
		self.initUI()

	def _centerlize(self):
		qr = self.frameGeometry()
		cp = QDesktopWidget().availableGeometry().center()
		qr.moveCenter(cp)
		self.move(qr.topLeft())

	def _get_seat_file_name(self):
		self._seat_file_name = QFileDialog.getOpenFileName(self, 'Open file', './')[0]
		if self._seat_file_name:
			self._choose_seat_file_edit.setText(self._seat_file_name)

	def _quit(self):
		self._sign = 0

	def _get_info(self):
		self._hawkid = self._enter_hawkid_edit.text()
		self._passwd = self._enter_passwd_edit.text()
		self._course = self._enter_course_edit.text()
		self._exam = self._enter_exam_edit.text()
		self._time = self._enter_time_edit.text()
		self._title = self._enter_title_edit.text()
		self._content = self._enter_content_edit.toPlainText()

	def _dump_config(self):
		self._get_info()
		conf = json.dumps({'Hawk ID': self._hawkid, 'Password': self._passwd, 'Course': self._course, 'Exam': self._exam, 'Time': self._time, 'Seat File': self._seat_file_name, 'Title State': self._title_state, 'Content State': self._content_state, 'Title': self._title, 'Content': self._content})
		with open('config.txt', 'w') as f:
			f.write(conf)
			f.close()
		self._status_edit.append('Configuration Dumped into config.txt\n')
		QCoreApplication.processEvents()

	def _load_config(self):
		_config_file = QFileDialog.getOpenFileName(self, 'Open file', './')[0]
		self._load_config_edit.setText(_config_file)
		with open(_config_file, 'r') as f:
			conf = json.load(f)
			f.close()
		try:
			self._hawkid = conf['Hawk ID']
			self._passwd = conf['Password']
			self._course = conf['Course']
			self._exam = conf['Exam']
			self._time = conf['Time']
			self._seat_file_name = conf['Seat File']
			self._title_state = conf['Title State']
			if self._title_state:
				self._enter_title_checkbox.setChecked(True)
			else:
				self._enter_title_checkbox.setChecked(False)
			self._title = conf['Title']
			self._content_state = conf['Content State']
			if self._content_state:
				self._enter_content_checkbox.setChecked(True)
			else:
				self._enter_content_checkbox.setChecked(False)
			self._content = conf['Content']
			self._enter_hawkid_edit.setText(self._hawkid)
			self._enter_passwd_edit.setText(self._passwd)
			self._enter_course_edit.setText(self._course)
			self._enter_exam_edit.setText(self._exam)
			self._enter_time_edit.setText(self._time)
			self._choose_seat_file_edit.setText(self._seat_file_name)
			self._enter_title_edit.setText(self._title)
			self._enter_content_edit.setText(self._content)
			self._status_edit.append('Configurations Load Complete!\n')
		except KeyError:
			self._status_edit.append('Key Error!')
		finally:
			QCoreApplication.processEvents()

	def _title_check(self, state):
		if state == Qt.Checked:
			self._title_state = True
		else:
			self._title_state = False

	def _content_check(self, state):
		if state == Qt.Checked:
			self._content_state = True
		else:
			self._content_state = False

	def initUI(self):
		choose_seat_file_button = QPushButton('Seat File', self)
		choose_seat_file_button.clicked.connect(self._get_seat_file_name)
		self._choose_seat_file_edit = QLineEdit()

		hawkid_label = QLabel('Hawk ID', self)
		self._enter_hawkid_edit = QLineEdit(self)

		passwd_label = QLabel('Password', self)
		self._enter_passwd_edit = QLineEdit(self)
		self._enter_passwd_edit.setEchoMode(QLineEdit.Password)

		course_label = QLabel('Course', self)
		self._enter_course_edit = QLineEdit(self)

		exam_label = QLabel('Exam', self)
		self._enter_exam_edit = QLineEdit(self)

		time_label = QLabel('Time', self)
		self._enter_time_edit = QLineEdit(self)

		send_button = QPushButton('Send', self)
		send_button.clicked.connect(self.run)
		cancel_button = QPushButton('Cancel', self)
		cancel_button.clicked.connect(self._quit)

		self._status_edit = QTextEdit(self)

		dump_config_button = QPushButton('Save Config', self)
		dump_config_button.clicked.connect(self._dump_config)
		load_config_button = QPushButton('Load Config', self)
		load_config_button.clicked.connect(self._load_config)
		self._load_config_edit = QLineEdit(self)

		self._enter_title_checkbox = QCheckBox('Enter title?', self)
		self._enter_title_checkbox.stateChanged.connect(self._title_check)
		self._enter_title_edit = QLineEdit(self)
		self._enter_content_checkbox = QCheckBox('Enter Content?', self)
		self._enter_content_checkbox.stateChanged.connect(self._content_check)
		self._enter_content_edit = QTextEdit(self)

		grid = QGridLayout()
		grid.setSpacing(10)
		row = 1
		grid.addWidget(hawkid_label, row, 0)
		grid.addWidget(self._enter_hawkid_edit, row, 1)
		grid.addWidget(passwd_label, row, 2)
		grid.addWidget(self._enter_passwd_edit, row, 3)
		row += 1
		grid.addWidget(course_label, row, 0)
		grid.addWidget(self._enter_course_edit, row, 1)
		grid.addWidget(exam_label, row, 2)
		grid.addWidget(self._enter_exam_edit, row, 3)
		grid.addWidget(time_label, row, 4)
		grid.addWidget(self._enter_time_edit, row, 5)
		row += 1
		grid.addWidget(choose_seat_file_button, row, 0)
		grid.addWidget(self._choose_seat_file_edit, row, 1, 1, 5)
		row += 1
		grid.addWidget(self._enter_title_checkbox, row, 0)
		grid.addWidget(self._enter_title_edit, row, 1, 1, 5)
		row += 1
		grid.addWidget(self._enter_content_checkbox, row, 0)
		grid.addWidget(self._enter_content_edit, row, 1, 3, 5)
		row += 3
		grid.addWidget(dump_config_button, row, 0)
		grid.addWidget(load_config_button, row, 1)
		grid.addWidget(self._load_config_edit, row, 2, 1, 2)
		grid.addWidget(send_button, row, 4)
		grid.addWidget(cancel_button, row, 5)
		row += 1
		grid.addWidget(self._status_edit, row, 0, 6, 6)

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
		if self._title_state:
			title = self._title.format(BUILDING = seat[0], ROOM = seat[1], SEAT = seat[2])
		else: 
			title = exam + " Seat: " + '-'.join(seat)
		if self._content_state:
			content = self._content.format(NAME = name, BUILDING = seat[0], ROOM = seat[1], SEAT = seat[2])
		else:
			exam = self._course + " " + self._exam
			content = "Dear " + name + ":\n\n" + "Your seat for " + exam + " is: " + "Building " + seat[0] + ", Room " + seat[1] + ", and Seat " + seat[2] + ". It is recommended that you explore your seat a day before the exam.\n" + "The Exam is on " + self._time
		return [name, email, title, content]

	def _send(self, msg, name, email, title, content):
		msg.setRecipients(email)
		msg.setSubject(title)
		msg.setBody(content)
		msg.sendMessage()

	def run(self):
		self._get_info()
		self._sign = 1
		if not self._seat_file_name or not self._hawkid or not self._passwd or not (self._title_state and self._content and not self._course and not self._exam and not self._time):
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