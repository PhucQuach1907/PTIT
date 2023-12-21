def Reduce(n):
    s = str(n)
    return int(s[:len(s)//2:]) + int(s[len(s)//2::])


n = int(input())
while len(str(n)) > 1:
    n = Reduce(n)
    print(n)
