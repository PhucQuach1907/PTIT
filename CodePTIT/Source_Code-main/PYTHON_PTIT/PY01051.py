def Solve():
    s = input()
    sum = 0
    for x in s:
        sum += int(x)
    sum = str(sum)
    print("YES" if len(sum) > 1 and sum == sum[::-1] else "NO")


for i in range(0, int(input())):
    Solve()
