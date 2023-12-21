import math


def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


primeNumber = [0]
for i in range(2, 8000, 1):
    if len(primeNumber) > 1000:
        break
    if isPrime(i):
        primeNumber.append(i)

n, x = map(int, input().split())
for i in range(0, n+1):
    print(x+primeNumber[i], end=" ")
    x = x+primeNumber[i]
