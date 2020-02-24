from math import gcd, sqrt
import sys

sys.stdin = open('input.txt', 'r')

def extendEuclid(a, b):
	xx = y = 0
	yy = x = 1
	oldA, oldB = a, b

	while b != 0:
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

	if (oldA * x + oldB * y < 0):
		x = -x
		y = -y

	return [x, y]

x0, y0, y1, x2, y1, y2, r = 0, 0, 0, 0, 0, 0, 0
res = 0
a0, b0 = 0, 0

def solve(c):
	A = a0 * c - x0
	B = (x1 - x2) // d
	C = b0 * c - y0
	D = (y1 - y2) // d

	det = (A*B + C*D) * (A*B + C*D) - (B * B + D * D) * (A * A + C * C - r * r)
	if (det < 0):
		return 0

	root1 = (-(A * B + C * D) - sqrt(det)) / (B * B + D * D) 
	root2 = (-(A * B + C * D) + sqrt(det)) / (B * B + D * D) 

	u1 = int(root1)
	u2 = int(root2)

	isTrue = 0

	for i in range(u1 - 3, u1 + 3):
		if ((A + B * i) * (A + B * i) + (C + D * i) * (C + D * i) <= r * r):
			u1 = i
			isTrue = 1
			break
	
	if (isTrue == 0):
		u1 += 3

	isTrue = 0

	for i in range(u2 + 3, u2 - 3, -1):
		if ((A + B * i) * (A + B * i) + (C + D * i) * (C + D * i) <= r * r):
			u2 = i
			isTrue = 1
			break

	if (isTrue == 0):
		u2 -= 3

	return max(0, u2 - u1 + 1)

if __name__ == '__main__':

	t = int(input())
	for z in range(1, t + 1):

		S = int(input())
		x0, y0, r = map(int, input().split())
		x1, y1, x2, y2 = map(int, input().split())

		
		rr = 0

		delta = x1 * y2 - x2 * y1

		d = gcd(abs(y1 - y2), abs(x1 - x2))

		[a0, b0] = extendEuclid(y1 - y2, x2 - x1)

		if (S % d != 0):
			print(0)
			continue
		res = 0
		res += solve((-delta - S) // d)
		res += solve((-delta + S) // d)

		print(res)