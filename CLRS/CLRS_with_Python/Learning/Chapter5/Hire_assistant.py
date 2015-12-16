#Hire Assistant
#15.7.18

def hire_assistant(A):
	best = 0
	flag = 0
	for i in range(len(A)):
		if A[i] > best:
			best = A[i]
			flag = i
	return flag

A = [1,43,23,3,65,2,1,56,45]
print(hire_assistant(A))