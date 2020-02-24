import matplotlib.pyplot as plt
import math

def f(y):
    return 10 * math.exp(0.06 * y)

y = range(0, 53, 1)
x = [f(i) for i in y]

plt.title("Number of Users after Weeks")
plt.xlabel("Weeks")
plt.ylabel("Number of Users")

plt.plot(y, x)
plt.show()