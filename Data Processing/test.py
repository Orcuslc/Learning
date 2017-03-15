import pandas as pd
import numpy as np

data = pd.read_csv('E:\\Desktop\\LSG_order_flow_16.csv', encoding='gb2312', index_col='date')
dates = sorted(list(set(data.index)))
types = sorted(list(set(data['type'])))

def sort_by_type():
	# grouped = data.groupby([data.index, 'type'])
	# print(grouped.first())
	# data2 = data.copy()
	# data2.index = pd.MultiIndex.from_arrays([dates, types], names = ['date', 'type'])
	nd = pd.DataFrame(np.zeros((len(dates), len(types))), columns = types, index = dates, dtype = 'int')
	for i in range(len(data.index)):
		nd.loc[data.index[i]][data.iloc[i]['type']] += data.iloc[i]['amount']
	return nd

def sort_by

if __name__ == '__main__':
	# print(dates)
	# print(types)
	# bd = sort_by_type()
	# bd.to_csv('E:\\Desktop\\LSG_order_flow_16_by_type.csv')
