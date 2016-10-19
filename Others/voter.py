import requests as rq
import pandas as pd
import random, time

class voter:
	def __init__(self, pid):
		self.url = "http://active.163.com/service/vote/v1/1260/digg.jsonp?id="+str(pid)+"&callback=_callback_0"
		self.headers = {
			# GET /service/vote/v1/1260/digg.jsonp?id=8&callback=_callback_0 HTTP/1.1
			"Host": "active.163.com",
			"User-Agent": "Mozilla/5.0 (Windows NT 10.0; WOW64; rv:49.0) Gecko/20100101 Firefox/49.0",
			"Accept": "*/*",
			"Accept-Language": "zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3",
			# "Accept-Encoding": gzip, deflate
			"Referer": "http://lady.163.com/special/sense/hanfuzhihua.html?from=timeline&isappinstalled=0",
			"Cookie": "P_INFO=orcuslc@163.com|1472803307|0|mail163|00&99|shh&1472775651&kaola#shh&null#10#0#0|130218&0|kaola|orcuslc@163.com; _ntes_nnid=d9db00f791dc6969b1d591214f4adfe4,1472774510478; _ntes_nuid=d9db00f791dc6969b1d591214f4adfe4; vjuids=-470240628.157dcd457d8.0.6623535fa21748; vjlast=1476878686.1476878686.30; ne_analysis_trace_id=1476878686194; vinfo_n_f_l_n3=274d2fc4309df1cf.1.0.1476878686206.0.1476878786446; s_n_f_l_n3=274d2fc4309df1cf1476878686210",
			"Connection": "keep-alive"
		}

	def _vote(self):
		r = rq.get(self.url, headers = self.headers)
		print(r.text)

	def run(self, n, td = 2):
		for i in range(n):
			# t = random.random()
			t = 0
			self._vote()
			time.sleep(t)

if __name__ == '__main__':
	v = voter(8)
	v.run(100)