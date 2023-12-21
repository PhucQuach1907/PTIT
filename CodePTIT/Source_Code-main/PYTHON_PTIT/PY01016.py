def Solve():
    str = input()
    for i in range(0, len(str), 2):
        print(str[i]*int(str[i+1]), end="")
    print("\n", end="")


for i in range(0, int(input())):
    Solve()
