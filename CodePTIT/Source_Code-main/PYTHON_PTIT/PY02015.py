def Solve(a, b, c, d):
    res = 0
    while a != 0 or b != 0 or c != 0 or d != 0:
        res += 1
        aa, bb, cc, dd = a, b, c, d
        a = abs(a-bb)
        b = abs(b-cc)
        c = abs(c-dd)
        d = abs(d-aa)
    print(res-1)


while True:
    a, b, c, d = map(int, input().split())
    if a == 0 and b == 0 and c == 0 and d == 0:
        break
    Solve(a, b, c, d)
