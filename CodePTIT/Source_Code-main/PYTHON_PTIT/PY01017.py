def Solve():
    str = input()
    i = 0
    while (i < len(str)):
        j = i
        while (j < len(str) and str[j] == str[i]):
            j += 1
        print(j-i, str[i], sep="", end="")
        i = j
    print("")


for i in range(0, int(input())):
    Solve()
