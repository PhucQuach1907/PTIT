def Solve():
    n, k = map(int, input().split())
    res, curPow, mod = 0, 1, int(1e9+7)
    while k:
        if k & 1:
            res = (res + curPow) % mod
        curPow = (curPow*n) % mod
        k >>= 1
    print(res)


for _ in range(int(input())):
    Solve()
