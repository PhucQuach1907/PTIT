import math


def isPrime(n):
    if (n < 2):
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


def Check(s):
    sum = 0
    for i in range(0, len(s)):
        sum += int(s[i])
        if i & 1:
            if (int(s[i]) % 2 == 0):
                return False
        else:
            if (int(s[i]) & 1):
                return False
    return True


def Solve():
    s = input()
    print("YES" if Check(s) else "NO")


for i in range(0, int(input())):
    Solve()
