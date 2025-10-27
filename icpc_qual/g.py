import sys

n, k = [int(i) for i in sys.stdin.readline().split()]

p = 998244353

top = (2 * k) ** (2 * k)
bottom = (2 * k + 1) ** (2 * k)

print(top / bottom)





