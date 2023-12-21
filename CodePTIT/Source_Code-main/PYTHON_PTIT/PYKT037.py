nmc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"


def Solve():
    n, b = map(int, input().split())
    res = ""
    while n:
        res += nmc[n % b]
        n //= b
    print(res[::-1])


for i in range(int(input())):
    Solve()
