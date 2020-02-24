inp = open("input.txt", "r")
data = (inp.read().split())
n = int(data[0])
d = int(data[1])
r = int(data[2])
c = [[0 for j in range (2005)] for i in range(2005)] 

c[0][0] = 1;
for i in range(1, 2001):
    c[i][0] = 1
    for j in range(1, i):
        c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    c[i][i] = 1

S = c[n + d - 1][n - 1]
res = 0

for k in range (1, n + 1):
    for y in range (1, n + d + 1):
        if  k * (y - 1) > d: break
        for i in range (0, n - k + 1):
            if (d - (k + i) * (y - 1) < 0): break
            
            V = c[n][k] * c[n - k][i] * c[n + d - (k + i) * (y - 1) - 1][n - 1] * min(k, r)
            if i % 2 == 0:
                res = res + V
            else:
                res = res - V

#print (res, S)

res = res / S
print(res)