def Solve():
    arr = list(input())
    print("YES" if arr == sorted(arr) else "NO")


for i in range(0, int(input())):
    Solve()
