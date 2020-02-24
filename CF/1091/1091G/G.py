import math
import random
from sys import stdout

prime = [3, 7, 11, 19, 23, 31, 43, 47, 59, 67, 71, 79, 83, 103, 107, 127, 131, 139, 151, 163, 167, 179, 191, 199, 211, 223, 227, 239, 251, 263, 271, 283, 307, 311, 331, 347, 359, 367, 379, 383, 419, 431, 439, 443, 463, 467, 479, 487, 491, 499, 503, 523, 547, 563, 571]
setPrime = set([])
	
def genInput():
	k = random.randint(2, 10)
	print(k)

	while len(setPrime) < k:
		setPrime.add(prime[random.randint(0, len(prime) - 1)])
	
	n = 1	
	for i in setPrime:
		print(i, end = ' ')
		n *= i		

	print(':', n)
	return n

def mu(a, n, p):
	if (n == 0):
		return 1
	q = mu(a, n // 2, p)
	if n % 2 == 0:
		return q * q % p
	else:
		return q * q * a % p

def sqrtMod(x, p):
	return mu(x, (p + 1) / 4, p)

def extendEuclid(a, b):
	xx = y = 0
	yy = x = 1
	while b > 0:
		q = a // b
		t = b
		b = a % b
		a = t
		t = xx
		xx = x - q * xx
		x = t
		t = yy
		yy = y - q * yy
		y = t

	return [x, y]


def ansQuery(x):
	res = 1
	prod = 1

	for p in setPrime:
		if (prod == 1):
			res = sqrtMod(x, p)
			prod = p
		else:
			curSqrt = sqrtMod(x, p)
			n0 = extendEuclid(prod, p)[0] * (curSqrt - res)
			n1 = -extendEuclid(prod, p)[1] * (curSqrt - res)
			
			prod *= p
			n1 = (n1 % prod + prod) % prod
			res = (n1 * p + curSqrt) % prod

	return res

def askQuery(x):
	# return ansQuery(x)
	print("sqrt", x)
	stdout.flush()
	a = int(input())
	return a

def update(a, res):
	tmpSet = set([])

	for i in res:
		u = math.gcd(i, a)
		if (u > 1) and (u < i):
			tmpSet.add(i // u)
			tmpSet.add(u)
		else:
			tmpSet.add(i)

	return tmpSet

if __name__ == '__main__':
	n = int(input())
# 	n = genInput()

	res = set([n])

	for z in range(80) :
		x = random.randint(2, n - 1)
		y = askQuery(x * x % n)

		a = math.gcd(n, (x + y) % n)
		b = math.gcd(n, abs(x - y) % n)

		res = update(a, res)
		res = update(b, res)

	print('!', len(res), end = ' ')

	for i in res:
		print(i, end = ' ')	

	stdout.flush()