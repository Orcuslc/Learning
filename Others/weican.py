import requests as rq
from bs4 import BeautifulSoup as BS
import sys, os, io, re

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding = 'utf-8')

class wencai:
	def __init__(self):
		self._headers = {
		# GET /stockpick/search?ts=1&f=1&qs=stockhome_topbar_click&w=20170303%20%E6%B6%A8%E5%81%9C%E9%9D%9E%E4%B8%80%E5%AD%97 HTTP/1.1
			'Accept': 'text/html, application/xhtml+xml, image/jxr, */*',
			'Accept-Language': 'zh-Hans-CN,zh-Hans;q=0.8,en-US;q=0.5,en;q=0.3',
			'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36 Edge/15.15046',
			'Accept-Encoding': 'gzip, deflate',
			'Host': 'www.iwencai.com',
			'Connection': 'Keep-Alive',
			'Pragma': 'no-cache'
		}

	def get_page(self, date):
		_url = 'http://www.iwencai.com/stockpick/search?ts=1&f=1&qs=stockhome_topbar_click&w=' + date + '%20%E6%B6%A8%E5%81%9C%E9%9D%9E%E4%B8%80%E5%AD%97'
		self._page = rq.get(_url, headers = self._headers).text

	def parse_page(self):
		soup = BS(self._page, "lxml")
		self._strings = soup.find_all(attrs = {'class': 'em'}, text = re.compile('[0-9]{6}'))

	def run(self, date):
		self.get_page(date)
		self.parse_page()
		return [i.string for i in self._strings]

if __name__ == '__main__':
	w = wencai()
	for date in ['20170303', '20170302']:
		print(w.run(date))