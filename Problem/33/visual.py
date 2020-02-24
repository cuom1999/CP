from matplotlib import pyplot as plt 
import numpy as np
from collections import defaultdict

a = [0, 1, 11, 17, 12, 2]

x = np.arange(0, 20, 0.05)
xs = []
ys = []

f = [defaultdict(float) for i in range(10)]

sumSq = sum([i * i for i in a])

for i in range(1, len(a)):
    for y in x:
        f[i][y] = 1e10
        
        for yy in x:
            if (yy <= y):
                f[i][y] = min(f[i][y], f[i - 1][yy] + (yy - a[i]) ** 2)
        
        if (i == len(a) - 1):
            xs.append(y)
            ys.append(f[i][y])

print([(x, y) for x, y in zip(xs, ys)])

plt.plot(xs, ys) 
# plt.plot(xs, [(y - 11)**2 + (y - 17)**2 + (y - 2)**2 for y in xs], color='red')
# plt.plot(xs, [(y - 11)**2 + (y - 17)**2 + (y - 12)**2 + (y - 2)**2 for y in xs], marker=',', color='red')
# plt.plot(xs, [4 * y * y - 28 * y + sumSq - 1 for y in xs], color = 'green')
# plt.plot(xs, [3 * y * y - 24 * y + sumSq - 5 for y in xs], color = 'yellow')

# plt.axis('equal')
plt.show()