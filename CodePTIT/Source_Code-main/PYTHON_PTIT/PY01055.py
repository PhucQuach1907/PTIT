def Check(s):
    if len(s) % 2 == 0:
        return False
    if (s[0] == s[1]):
        return False
    for i in range(2, len(s)+1, 2):
        if s[i] != s[i-2]:
            return False
    return True


def Solve():
    s = input()
    print("YES" if Check(s) else "NO")


for i in range(0, int(input())):
    Solve()
