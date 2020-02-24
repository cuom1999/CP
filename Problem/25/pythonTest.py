import sys

MAXN = 1505

a = [[0 for i in range(MAXN)] for j in range(MAXN)]
s = [[0 for i in range(MAXN)] for j in range(MAXN)]
res = [0 for i in range(MAXN)]

sys.stdin = open('input.txt', 'r')

def check(x1, y1, x2, y2):
	val = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]
	if (val == (y2 - y1 + 1) * (x2 - x1 + 1)):
		return 1
	return 0


if __name__ == '__main__':

	n = int(input())
	m = int(input())

	for i in range(1, n + 1, 1):
		rowTmp = input().split()
		for j in range(1, m + 1, 1):
			c = rowTmp[j - 1]
			if c == '.':
				a[i][j] = 1

	for i in range(1, n + 1, 1):
		for j in range(1, m + 1, 1):
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j]

	for i in range(1, n + 1, 1):
		for j in range(1, m + 1, 1):
			if a[i][j] == 0:
				continue
			L = 0
			R = min(n - i, m - j)

			while (L < R):
				mid = (L + R + 1) // 2
				if (check (i, j, i + mid, j + mid) == 1):
					L = mid
				else:
					R = mid - 1

			res[L + 1] += 1

	for i in range(min(n, m) - 1, 0, -1):
		res[i] += res[i + 1]

	for i in range (1, min(m, n) + 1, 1):
		print(res[i], end = ' ')