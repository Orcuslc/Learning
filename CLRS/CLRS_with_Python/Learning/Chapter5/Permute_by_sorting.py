#Permute by sorting
#15.7.18

import random

def permute_by_sorting(A):
	P = []
	for i in range(len(A)):
		P.append(random.randint(1, len(A) ^ 3))
		