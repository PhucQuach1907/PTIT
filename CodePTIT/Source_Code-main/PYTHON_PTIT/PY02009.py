from collections import defaultdict


def Solve():
    n = int(input())
    arr = []
    cnt = defaultdict(int)
    for i in range(0, n):
        x = int(input())
        arr.append(x)
        cnt[x] += 1
    maxAppear, res = 0, -1
    diff = set(arr)
    for x in diff:
        if cnt[x] > maxAppear:
            res = x
            maxAppear = cnt[x]
        elif cnt[x] == maxAppear:
            res = min(res, x)
    print(res)


for i in range(0, int(input())):
    Solve()
