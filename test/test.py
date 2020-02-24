import sys

sys.stdin = open('input.txt', 'r')

MAXN = 1005

comp = [0 for i in range(MAXN)]
d = [0 for i in range(MAXN)]

if __name__ == '__main__':
	n = int(input())
	for i in range(2, n + 1):
		for j in range(2, n // i + 1):
			comp[i * j] = 1

	for i in range(2, n + 1):
		if (comp[i] == 0):
			d[i] = 1

		for j in range(2, i + 1):
			if (comp[j] == 0):
				d[i] += d[i - j]

	print(d[n])