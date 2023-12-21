import math


def isPrime(n):
    if (n < 2):
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def Solve():
    str = input()
    primeDigit = 0
    for x in str:
        primeDigit += 1 if x == "2" or x == "3" or x == "5" or x == "7" else 0
    print("YES" if isPrime(len(str)) and primeDigit >
          len(str)-primeDigit else "NO")


for i in range(0, int(input())):
    Solve()
