import math


def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def getReverse(n):
    return int(str(n)[::-1])


def Check(n):
    sumDigit = 0
    digitArr = list(str(n))
    for x in digitArr:
        if x != "2" and x != "3" and x != "5" and x != "7":
            return False
        sumDigit += int(x)
    if not isPrime(sumDigit):
        return False
    if not isPrime(n):
        return False
    if not isPrime(getReverse(n)):
        return False
    return True


def Solve():
    n = int(input())
    print("Yes" if Check(n) else "No")


for _ in range(int(input())):
    Solve()
