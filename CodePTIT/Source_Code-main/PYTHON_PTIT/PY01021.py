def Solve():
    str = input()
    res, sum = [], 0
    for x in str:
        if x.isalpha():
            res.append(x)
        else:
            sum += int(x)
    res.sort()
    print("".join(res), sum, sep="")


for i in range(int(input())):
    Solve()
