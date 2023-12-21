def Solve():
    str = input()
    print("YES" if str.count("0")+str.count("1") +
          str.count("2") == len(str) else "NO")


for i in range(0, int(input())):
    Solve()
