import math


def isPrime(n):
    if (n < 2):
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def Check(str):
    if (not isPrime(len(str))):
        return False
    primeDigit = 0
    for x in str:
        if x == "2" or x == "3" or x == "5" or x == "7":
            primeDigit += 1
    return True if primeDigit > len(str)-primeDigit else False


def Solve():
    print("YES" if (Check(input())) else "NO")


for i in range(0, int(input())):
    Solve()
