def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    res = 0
    for x in arr:
        res ^= x
    print(res)


for _ in range(int(input())):
    Solve()
