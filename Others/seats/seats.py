import sys
import csv
from O365 import Message

###### configuration ######
loginid = ********
password = *******
authenticiation = (loginid, password)
###########################

path = sys.argv[1]

def _parse(row):
	[name, hawkid, seat] = row
	email = hawkid + "@iowa.uiowa.edu"
	title = "MATH:1380 Mid Term 1 Seat: " + seat
	content = "Dear " + name + ":\n" + "Your seat for MATH:1380 Mid Term 1 is: " + seat + "\n" + "PLEASE IGNORE THE LAST EMAIL ABOUT YOUR MID TERM 1 SEAT IF YOU RECEIVED ONE, SINCE THIS IS AN UPDATED VERSION. Thank you!"
	return [name, email, title, content]

def send(msg, name, email, title, content):
	msg.setRecipients(email)
	msg.setSubject(title)
	msg.setBody(content)
	msg.sendMessage()


with open(path, newline = '') as f:
	m = Message(auth = authenticiation)
	data = csv.reader(f)
	for row in data:
		[name, email, title, content] = _parse(row)
		send(m, name, email, title, content)
		print(name + " Sent!")
	f.close()

