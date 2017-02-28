import pandas as pd
import datetime as dt

def get_minutes():
	minutes_delta = dt.timedelta(0, 60)
	seconds_delta = dt.timedelta(0, 1)
	return [seconds_delta*33300 + minutes_delta*i for i in range(135)]+[seconds_delta*46800 + minutes_delta*i for i in range(135)]

def get_dates(data):
	dates = sorted(list(set([str(i).split(' ')[0] for i in data.index])))
	return [dt.datetime(int(date[:4]), int(date[5:7]), int(date[8:])) for date in dates]

# def get_time_list(start, end):
# 	s, e = start.split('/'), end.split('/')
# 	start = dt.datetime(int(s[0]), int(s[1]), int(s[2]))
# 	end = dt.datetime(int(e[0]), int(e[1]), int(e[2]))
# 	dates = (end - start).days
# 	date_delta = dt.timedelta(1)
# 	minutes_list = get_minutes()
# 	return [time.strftime('%Y-%m-%d %H:%M:%S') for time in [start + i + j*date_delta for j in range(dates + 1) for i in minutes_list]], [270*i for i in range(dates)]

def get_time_list(dates):
	minutes_list = get_minutes()
	return [time.strftime('%Y-%m-%d %H:%M:%S') for time in [i + j for j in dates for i in minutes_list]], [270*i for i in range(len(dates))]

def handle_first_minute(data, day_index):
	for index in day_index:
		first_minute = data.iloc[index]
		if first_minute.isnull()['开盘价'] == True:
			count = 1
			while True:
				ndata = data.iloc[index + count]
				if ndata.isnull()['开盘价'] != True:
					break
				count += 1
			data.iloc[index] = ndata
	return data

# def run(path, save_path, start, end):
# 	time, day_index = get_time_list(start, end)
# 	handle_first_minute(pd.concat([get_time_list(get_dates(pd.read_excel(path, index_col='时间',) day_index)

def run(path, save_path):
	data = pd.read_excel(path, index_col='时间')
	dates = get_dates(data)
	time, day_index = get_time_list(dates)
	handle_first_minute(pd.concat([data, pd.DataFrame(index = pd.Series(time, name = '时间'))], axis = 1), day_index).fillna(method = 'pad').to_excel(save_path, index_label = '时间')

if __name__ == '__main__':
	run(path = 'E:\\Desktop\\demo.xls', save_path = 'E:\\Desktop\\result.xlsx')
	print('Done')