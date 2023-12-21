isPrime = [True for i in range(1005)]


def Sieve():
    isPrime[0] = isPrime[1] = False
    for i in range(2, 503):
        if isPrime[i]:
            isPrime[2*i:1005:i] = [False for j in range(2*i, 1005, i)]


Sieve()

n = int(input())
arr = list(map(int, input().split()))
primeNumber = []
for x in arr:
    if isPrime[x]:
        primeNumber.append(x)
primeNumber.sort()
i = 0
for x in arr:
    if isPrime[x]:
        print(primeNumber[i], end=" ")
        i += 1
    else:
        print(x, end=" ")
