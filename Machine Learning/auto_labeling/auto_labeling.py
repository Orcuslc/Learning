# Auto Labeling
# author: orcuslc@hotmail.com
# Copyleft Orcuslc 2016
# This script is under GNU License.

# import io
import json
# import codecs
import requests
# import sys
import re
import random
import time

# sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf8')

class Naive_Label_Client:
	def __init__(self, user_name):
		self.user_name = user_name
		self._url = 'http://139.129.29.101'
		self._headers = {
			# GET / HTTP/1.1
			'Accept': 'text/html, application/xhtml+xml, image/jxr, */*',
			'Accept-Language': 'zh-Hans-CN,zh-Hans;q=0.8,en-US;q=0.5,en;q=0.3',
			'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/48.0.2564.82 Safari/537.36 Edge/14.14328',
			# 'Accept-Encoding': 'gzip, deflate',
			'If-Modified-Since': 'Tue, 19 Apr 2016 04:15:32 GMT',
			'If-None-Match': "f4a-530ceba6483fa-gzip",
			'Host': '139.129.29.101',
			'Connection': 'Keep-Alive',
			'Pragma': 'no-cache'
		}

	def _get_page(self):
		r = requests.get(self._url).content.decode('utf-8')
		result = re.findall(r'用户名', r)
		if result != []:
			self._connected = True
		else:
			self._connected = False

	def _post_user(self):
		post_data = {
			'user' : self.user_name
		}
		p = requests.post(self._url + '/gethistory.php', data = post_data)
		result = re.findall(r'你好', p.content.decode('utf-8'))
		if result != []:
			self._user = True
		else:
			self._user = False
		
	def _get_count(self):
		g = requests.get(self._url + '/getdata.php').content.decode('utf-8')
		# print(g)
		count = re.findall(r'\|[0-9]*', g)[0][1:]
		if count:
			self._count = True
			return count
		else:
			self._count = False

	def _labeling(self, count):
		label = random.choice([-1, 0, 1])
		post_data = {
			'count':count,
			'label':label,
			'user':self.user_name
		}
		p = requests.post(self._url + '/postlabel.php', data = post_data)
		result = re.findall(r'结果已储存', p.content.decode('utf-8'))
		if result != []:
			self._label = True
		else:
			self._label = False
		
	def _iter(self):
		time1 = time.time()
		if self._connected and self._user:
			count = self._get_count()
			self._labeling(count)
		time2 = time.time()
		print('%s finished, the time is %f s.'%(count, time2-time1))

	def run(self, max_iter):
		self._get_page()
		self._post_user()
		for i in range(max_iter):
			self._iter()
			time.sleep(0.1)


if __name__ == '__main__':
	l = Naive_Label_Client("胡元焊")
	l.run(10)