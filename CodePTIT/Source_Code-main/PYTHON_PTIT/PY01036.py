def Solve():
    n = int(input())
    res = 0
    start = 1 if n & 1 else 2
    for i in range(start, n+1, 2):
        res += 1/i
    print("%.6f" % (res))


for i in range(0, int(input())):
    Solve()
