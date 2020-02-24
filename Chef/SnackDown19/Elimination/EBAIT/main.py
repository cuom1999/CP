from fractions import Fraction
import sys

sys.stdin = open('input.txt', 'r')

if __name__ == '__main__':
	t = int(input())

	for z in range(0, t):
		N, C1, C2 = map(int, input().split())

		data = input().split()
		v = [0 for i in range(0, N + 1)]

		for i in range(1, N + 1):
			v[i] = int(data[i - 1])

		L = Fraction()
		R = Fraction(int(2e9), 1)

		sumA = 0
		sumB = 0

		if (N % 2 != 0):
			print(-1)
		else:
			for i in range(1, N // 2):
				sumA += v[i * 2 - 1]
				sumB += v[i * 2]
				L = max(L, Fraction(sumB, sumA))
			sumA += v[N - 1]
			sumB += v[N]

			R = Fraction(sumB, sumA)
			L = max(L, Fraction(sumB - 1, sumA))

			if (L >= R):
				print(-1)
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
			resY = lower
			resX = (lower * L.numerator) // L.denominator + 1
			if (resX <= C1 and resY <= C2):
				print(resX, resY)
			else:
				print(-1)
