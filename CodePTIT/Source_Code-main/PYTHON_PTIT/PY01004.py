import math


def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def Solve():
    n = int(input())
    res = 0
    for i in range(1, n):
        res += 1 if math.gcd(i, n) == 1 else 0
    print("YES" if isPrime(res) else "NO")


t = int(input())
while t:
    Solve()
    t -= 1
