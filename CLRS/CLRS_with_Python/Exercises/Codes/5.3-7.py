#5.3-7
#15.8.3
import random
def random_sample(m, n):
	S = []
	if m == 0:
		return []
	else:
		S = random_sample(m-1, n-1)
		print(S)
		i = random.randint(1, n)
		if i in S:
			S.append(n)
		else:
			S.append(i)
		print(S)
		return S

def random_sample(A, n):
	#蓄水池抽样方法，对于样本容量无穷大或者近乎无穷大的抽样，或者样本容量未知的抽样
	#Reservoir Sampling
	sample = A[:n]
	for x in range(n, len(A)):
		m = random.randint(1, x)
		if m < n:
			choice = random.randint(0, n-1)
			sample[choice], A[x] = A[x], sample[choice]
	return sample
A = [1,2,3,4,5,6,7,8,9,10]
n = 2
print(random_sample(A, n))

