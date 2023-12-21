import math


def isPrime(n):
    if (n < 2):
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def Solve():
    s = input()
    sum = 0
    for x in s:
        sum += int(x)
    print("YES" if isPrime(sum) else "NO")


for i in range(0, int(input())):
    Solve()
