from socket import *
import os

class Web_Server:
	def __init__(self, port = 9001):
		self.socket = socket(AF_INET, SOCK_DGRAM)
		self.socket.bind(('', port))
		print('Bind Succeed')
		self._run()

	def _run(self):
		while True:
			message, client_address = self.socket.recvfrom(8192)
			if message == 'Close':
				break
			# if not os.path.isfile(message):
				# response = "404 Not Found"
			self.socket.sendto([message, 404], address)

class Mail_Server:
	pass

if __name__ == '__main__':
	WS = Web_Server(8999)