def Solve():
    s = input()
    sum, product = 0, 1
    for i in range(0, len(s)):
        if (i & 1):
            if (int(s[i]) != 0):
                product *= int(s[i])
        else:
            sum += int(s[i])
    if product == 1:
        product = 0
    print(sum, product)


for i in range(0, int(input())):
    Solve()
