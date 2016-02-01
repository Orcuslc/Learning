import random

def gcd(a, b):
	if b == 0:
		return a
	else:
		return gcd(b, a % b)

def pollard_rho(n):
	i = 1
	x = random.randint(0, n - 1)
	y = x
	k = 2
	while True:
		i += 1
		x = (x ** 2 - 1) % n
		d = gcd(y - x, n)
		if d != 1 and d != n:
			return d
		if i == k:
			y = x
			k *= 2

if __name__ == '__main__':
	n = 1387
	d = pollard_rho(n)
	print(d)
