def Solve():
    cnt_num = 0
    num = list(input().split("."))
    for x in num:
        if not x.isdigit():
            print("NO")
            return
        if int(x) < 0 or int(x) > 255:
            print("NO")
            return
        cnt_num += 1
    print("YES" if cnt_num == 4 else "NO")


for _ in range(int(input())):
    Solve()
