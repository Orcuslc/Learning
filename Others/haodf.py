import requests as rq
import sys
from bs4 import BeautifulSoup as BS
import io

sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding = 'utf-8')

class haodf:
	def __init__(self):
		self.url = "http://www.haodf.com/hospital/DE4roiYGYZwXGaOyZJ9SvRJb8.htm"	
		self.headers = {
			# GET / HTTP/1.1
			"Accept": "text/html, application/xhtml+xml, image/jxr, */*",
			"Accept-Language": "zh-Hans-CN,zh-Hans;q=0.8,en-US;q=0.5,en;q=0.3",
			"User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36 Edge/15.14965",
			"Accept-Encoding": "gzip, deflate",
			"Host": "www.haodf.com",
			#"Host": "www.erji.net",
			"Connection": "Keep-Alive",
			}

	def get(self):
		r = rq.get(self.url, headers = self.headers).content.decode('gbk')
		bs = BS(r)
		for link in bs.find_all('a'):
			print(link.get('href'))
		

if __name__ == '__main__':
	h = haodf()
	h.get()
