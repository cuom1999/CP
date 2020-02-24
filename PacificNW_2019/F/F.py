import sys
sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

n, m, pos = map(int, input().split())

f = [[[0 for i in range(55)] for j in range(55)] for k in range(55)]
c = [[0 for i in range(55)] for j in range(55)]
fact = [0 for i in range(55)]

c[0][0] = 1
fact[0] = 1

for i in range(51):
    c[i][0] = 1
    if (i > 0):
        fact[i] = fact[i - 1] * i
    for j in range(1, 51):
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j]

f[0][0][0] = 1 #f[i][j][k]: i numbers, j useful, k fixed points
for i in range(1, n + 1):
    for j in range(0, i + 1):
        sumAll = fact[i]
        for k in range(1, j + 1):
            f[i][j][k] = f[i - k][j - k][0] * c[j][k]
            sumAll -= f[i][j][k]
            # print(i, j, k, f[i][j][k])
        f[i][j][0] = sumAll

# construct
res = [0 for _ in range(n + 1)]
used = [0 for _ in range(n + 1)]
isUseful = [1 for _ in range(0, n + 1)]
isUseful[0] = 0

if (f[n][n][m] < pos):
    print(-1)
    exit(0)

for i in range(1, n + 1):
    sumSmaller = 0
    lastSum = 0
    for val in range(1, n + 1):
        lastSum = sumSmaller
        if (used[val]):
            continue

        useful = sum(isUseful)    

        if (isUseful[i]):
            if (val == i):
                sumSmaller += f[n - i][useful - 1][m - 1]
            elif (isUseful[val]):
                sumSmaller += f[n - i][useful - 2][m]
            else:
                sumSmaller += f[n - i][useful - 1][m]
        else:
            if (isUseful[val] == 1):
                sumSmaller += f[n - i][useful - 1][m]
            else:
                sumSmaller += f[n - i][useful][m]

        if (sumSmaller >= pos):
            pos -= lastSum
            res[i] = val
            isUseful[i] = isUseful[val] = 0
            used[val] = 1
            if (i == val):
                m -= 1

            # print(res[i], pos, sumSmaller, m)
            break

for i in range(1, n + 1):
    print(res[i], end = ' ')