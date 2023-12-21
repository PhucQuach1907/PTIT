def Solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    x, y, z = 0, 0, 0
    res = []
    while x < n and y < m and z < k:
        if a[x] == b[y] == c[z]:
            res.append(a[x])
            x += 1
            y += 1
            z += 1
        elif a[x] < b[y]:
            x += 1
        elif b[y] < c[z]:
            y += 1
        else:
            z += 1
    print(" ".join(map(str, res)) if len(res) > 0 else "NO")


for _ in range(int(input())):
    Solve()
