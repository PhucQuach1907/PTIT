def Solve():
    num = input()
    res = 1
    for x in num:
        res *= 1 if x == "0" else int(x)
    print(res)


for i in range(0, int(input())):
    Solve()
