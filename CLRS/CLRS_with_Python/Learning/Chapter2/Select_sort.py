#select_sort
#15.7.15

def select_sort(A):                #o(n^2) in both best and worst situations。。                           
	for index in range(len(A)):  #n+1
		flag = index   #n。
		for i in range(index + 1, len(A)):  #n(n-1)/2
			if A[i] < A[flag]:      #(n-1)(n-2)/2
				flag = i            #worst: (n-1)(n-2)/2; best: 0
		A[index], A[flag] = A[flag], A[index]	#n
		return A

A = [4,1,8,2,564,65,2,1]
result = select_sort(A)
print(result)
