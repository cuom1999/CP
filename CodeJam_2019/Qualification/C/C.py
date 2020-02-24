from math import gcd
import sys

sys.stdin = open('input.txt', 'r')

primeList = set([])
a = []
p = []
cryp = dict([])

if __name__ == '__main__':
	t = int(input())

	for z in range(1, t + 1):
		print('Case #' + str(z) + ': ', end = '')

		n, l = map(int, input().split())

		a = input().split()
		
		for i in range(0, len(a)):
			a[i] = int(a[i])

		startIndex = 0

		for i in range(len(a) - 1):
			if (a[i] != a[i + 1]):
				startIndex = i
				break

		for i in range(l + 1):
			p.append(0)

		p[startIndex + 1] = gcd(a[startIndex], a[startIndex + 1])


		for i in range(startIndex, -1, -1):
			p[i] = a[i] // p[i + 1]

		for i in range(startIndex + 2, l + 1, 1):
			p[i] = a[i - 1] // p[i - 1]

		for i in p:
			primeList.add(i)

		cnt = 0
		for i in sorted(primeList):
			cryp[i] = chr(ord('A') + cnt)
			cnt += 1

		for i in p:
			print(cryp[i], end = '')

		print()

		cryp.clear()
		primeList.clear()
		p.clear()

