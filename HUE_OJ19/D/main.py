import sys
sys.stdin = open('input.txt', 'r')

n = int(input())
v = []

for i in range(1, n + 1, 1):
	x, y = map(int, input().strip().split())
	v.append(x + y)

v.sort()

res = 0
pw = 1

for i in v:
	res += pw * i
	pw *= 10

print(res)