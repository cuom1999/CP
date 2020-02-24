import sys
sys.stdin = open('input.txt', 'r')
n, p, b = map(int, input().split())

dp = [[0.0 for j in range(1005)] for i in range(1005)]

asciiValues = []

for i in range(97, 123, 1):
	asciiValues.append(i)
for i in range(65, 91, 1):
	asciiValues.append(i)

curVal = 1
dp[0][0] = 100

for i in range(1, n + 1, 1):
	for c in range(0, len(asciiValues), 1):
		val = curVal * asciiValues[c] % p
		for j in range(p):
			dp[i][j] += dp[i - 1][(j + p - val) % p] / 52.0
	curVal = curVal * b % p;		

for i in range(p):
	print("%.8f" % (dp[n][i]), end = ' ')