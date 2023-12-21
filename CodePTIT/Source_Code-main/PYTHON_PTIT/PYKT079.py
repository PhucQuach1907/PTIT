from collections import defaultdict


def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    myMap = defaultdict(int)
    for x in arr:
        myMap[x] += 1
    l, r = min(arr), max(arr)
    res = 0
    for i in range(l, r+1):
        if myMap[i] == 0:
            res += 1
    print(res)


for _ in range(int(input())):
    Solve()
