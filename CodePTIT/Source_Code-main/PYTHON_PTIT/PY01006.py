def Solve():
    str = input()
    cnt = str.count("4")+str.count("7")
    print("YES" if cnt == len(str) else "NO")


t = int(input())
while t:
    Solve()
    t -= 1
