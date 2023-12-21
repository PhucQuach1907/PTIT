def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    l, r = [-1]*(n+1), [10**18]*(n+1)
    for i in range(0, n):
        l[i+1] = max(l[i], arr[i])
    for i in range(n-1, -1, -1):
        r[i] = min(r[i+1], arr[i])
    res = 0
    for i in range(n):
        res += 1 if l[i] <= arr[i] and r[i+1] > arr[i] else 0
    print(res)


for _ in range(int(input())):
    Solve()
