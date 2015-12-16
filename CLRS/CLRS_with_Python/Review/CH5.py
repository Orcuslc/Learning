#Review on chapter 5
#15.7.31
import random
import sys
sys.setrecursionlimit(1000000)
def hire_assistant(A):
	best = A[0]
	for index in range(len(A)):
		if A[index] > A[best]:
			best = index
	return index

def permute_by_sorting(A):
	n = len(A)
	P = []
	for i in range(n):
		P.append(random.randint(0, n^3))
	for j in range(1, len(A)):
		key = P[j]
		anokey = A[j]
		i = j - 1
		while i >= 0 and A[i] > key:
			P[i+1] = P[i]
			A[i+1] = A[i]
			i -= 1
		P[i+1] = key
		A[i+1] = anokey
	return A

def randomize_in_place(A):
	n = len(A)
	for i in range(n):
		j = random.randint(i, n - 1)
		A[i], A[j] = A[j], A[i]
	return A

#def permute_by_sorting_advanced(A):

def power(m, n = 365):
	if m == 1:
		return n
	return n * power(m - 1)

def fact(m, n = 365):
	f = n - m
	if m == 1:
		return n-m+1
	return (f + m) * fact(m - 1)

def calc_possibility_of_birthday():
	#5.4.1(shengribeilun)
	for m in range(100):
		print(fact(m))
		print(power(m))
		if (fact(m))/(power(m)) <= 0.5:
			return m

#print(calc_possibility_of_birthday())

def on_line_maxmium(k, n, score):
	bestscore = inf('-float')
	for i in range(k):
		if score[i] > bestscore:
			bestscore = score[i]
	for i in range(k, n):
		if score[i] > bestscore:
			return i 
	return n

