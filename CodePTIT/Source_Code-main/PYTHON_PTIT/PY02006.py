def Solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    for i in range(0, n):
        if a[i] > b[i]:
            print("NO")
            return
    print("YES")


for i in range(0, int(input())):
    Solve()
