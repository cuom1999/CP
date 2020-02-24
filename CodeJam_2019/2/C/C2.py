from fractions import Fraction
import sys

sys.stdin = open('input.txt', 'r')


if __name__ == '__main__':
	t = int(input())

	for z in range(1, t + 1):
		print('Case #' + str(z) + ': ', end = '')
		L = Fraction()
		R = Fraction(int(2e9), 1)

		n = int(input())
		a = [[0, 0] for i in range (0, n + 1)]
		
		for i in range(1, n + 1):
			a[i][0], a[i][1] = map(int, input().split())

		for i in range(1, n + 1):
			for j in range(i + 1, n + 1):
				if (a[i][0] > a[j][0]) and (a[i][1] < a[j][1]):
					L = max(L, Fraction(a[i][0] - a[j][0], a[j][1] - a[i][1]))
				elif (a[i][0] > a[j][0]):
					R = Fraction(0, 1)
				elif (a[i][0] < a[j][0]) and (a[i][1] > a[j][1]):
					R = min(R, Fraction(a[j][0] - a[i][0], a[i][1] - a[j][1]))
				elif (a[i][0] == a[j][0]) and (a[i][1] > a[j][1]):
					R = Fraction()

		if (L >= R):
			print('IMPOSSIBLE')
			continue

		X = (L + R) / 2
	
		lower = 1
		upper = int(2e9)

		while (lower < upper):
			mid = (lower + upper) // 2
			frac = X.limit_denominator(mid)
			if (frac < R) and (frac > L):
				upper = mid
			else:
				lower = mid + 1

		print(lower, (lower * L.numerator) // L.denominator + 1)
