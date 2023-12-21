import math


def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def Check(n):
    sum = 0
    while (n):
        sum += n % 10
        n //= 10
    return isPrime(sum)


def Solve():
    a, b = map(int, input().split())
    print("YES" if Check(math.gcd(a, b)) else "NO")


for i in range(0, int(input())):
    Solve()
