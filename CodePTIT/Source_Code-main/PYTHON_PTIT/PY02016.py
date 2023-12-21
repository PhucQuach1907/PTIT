from collections import defaultdict


def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    cnt = defaultdict(int)
    for x in arr:
        cnt[x] += 1
    res = 1000000000
    for x in list(cnt.keys()):
        if (cnt[x] > n//2):
            res = min(res, x)
    print(res if res != 1000000000 else "NO")


for i in range(0, int(input())):
    Solve()
