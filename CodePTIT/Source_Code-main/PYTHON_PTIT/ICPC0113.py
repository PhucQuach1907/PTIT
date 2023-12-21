isPrime = [True for i in range(1000005)]


def Sieve():
    isPrime[0] = isPrime[1] = False
    for i in range(2, 500005):
        if isPrime[i]:
            isPrime[2*i:1000005:i] = [False for j in range(2*i, 1000005, i)]


Sieve()


def getReverse(n):
    return int(str(n)[::-1])


def Solve():
    n = int(input())
    res = 0
    for i in range(2, n):
        ii = getReverse(i)
        if isPrime[i] and isPrime[ii] and ii < n and i < ii and i != ii:
            print(i, ii, sep=" ", end=" ")
    print()


for _ in range(int(input())):
    Solve()
