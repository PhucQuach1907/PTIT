def Solve():
    p, q = map(str, input().split())
    arr = input().split()
    if (len(arr) > 1):
        x1, x2 = arr[0], arr[1]
    else:
        x1 = arr[0]
        x2 = input()
    res1 = int(x1.replace(p, q)) + int(x2.replace(p, q))
    res2 = int(x1.replace(q, p)) + int(x2.replace(q, p))
    print(min(res1, res2), max(res1, res2))


for i in range(0, int(input())):
    Solve()
