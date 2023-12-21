def Solve():
    n, d = map(int, input().split())
    arr = list(input().split())
    print(" ".join(arr[d::]+arr[:d:]))


for i in range(0, int(input())):
    Solve()
