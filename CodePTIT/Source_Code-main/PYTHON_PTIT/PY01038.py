def reverseNumber(n):
    return int(str(n)[::-1])


def Solve():
    n = int(input())
    loopNumber = 0
    while (loopNumber <= 1000):
        if n % 7 == 0:
            print(n)
            return
        n = n + reverseNumber(n)
        loopNumber += 1
    print(-1)


for i in range(int(input())):
    Solve()
