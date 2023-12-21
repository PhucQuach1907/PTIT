def Solve():
    s = list(input())
    l, r, n = 0, 0, len(s)
    for i in range(n):
        if i < n//2:
            l += ord(s[i])-65
        else:
            r += ord(s[i])-65
    for i in range(n):
        if i < n//2:
            s[i] = chr((ord(s[i])-65+l) % 26 + 65)
        else:
            s[i] = chr((ord(s[i])-65+r) % 26 + 65)
    for i in range(n//2):
        s[i] = chr((ord(s[i]) - 65 + ord(s[i + n // 2]) - 65) % 26 + 65)
    print("".join(s[:n//2:]))


for _ in range(int(input())):
    Solve()
