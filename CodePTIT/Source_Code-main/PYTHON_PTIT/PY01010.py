def Solve():
    str = input()
    start = str[0]+str[1]
    print("YES" if str.endswith(start) else "NO")


for i in range(0, int(input())):
    Solve()
