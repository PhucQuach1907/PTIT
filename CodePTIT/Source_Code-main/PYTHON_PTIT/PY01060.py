def Solve():
    s = input()
    sum, product = 0, 1
    for i in range(0, len(s)):
        if (i & 1):
            sum += int(s[i])
        else:
            if (int(s[i]) != 0):
                product *= int(s[i])
    print(product, sum)


for i in range(0, int(input())):
    Solve()
