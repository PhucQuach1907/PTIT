def Solve():
    str = input()
    if len(set(str)) != 2:
        print("NO")
        return
    for i in range(2, len(str), 2):
        if str[i] != str[i-2]:
            print("NO")
            return
    for i in range(3, len(str), 2):
        if str[i] != str[i-2]:
            print("NO")
            return
    print("YES")


for i in range(0, int(input())):
    Solve()
