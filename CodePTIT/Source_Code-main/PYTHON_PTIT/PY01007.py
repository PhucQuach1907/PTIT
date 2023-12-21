import math


def Solve():
    n, x, m = map(float, input().split())
    ans = 0
    while (True):
        if (n*math.pow(1+x/100, ans) >= m):
            print(ans)
            return
        ans += 1


for i in range(0, int(input())):
    Solve()
