def Solve():
    str = input()
    n = len(str)
    if n < 3:
        print("NO")
        return
    i = 0
    while i < n-1 and str[i] < str[i+1]:
        i += 1
    if i == 0 or i == n-1:
        print("NO")
        return
    while i < n-1 and str[i] > str[i+1]:
        i += 1
    print("YES" if i == n-1 else "NO")


for i in range(0, int(input())):
    Solve()
