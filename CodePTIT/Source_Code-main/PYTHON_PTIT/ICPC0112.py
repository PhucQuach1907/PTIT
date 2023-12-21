isPrime = [True for i in range(1000005)]


def Sieve():
    isPrime[0] = isPrime[1] = False
    for i in range(2, 500005):
        if isPrime[i]:
            isPrime[2*i:1000005:i] = [False for j in range(2*i, 1000005, i)]


Sieve()


def Solve():
    n = int(input())
    res = 0
    for i in range(2, n):
        if i+6 < n:
            if (isPrime[i] and isPrime[i+2] and isPrime[i+6]) or (isPrime[i] and isPrime[i+4] and isPrime[i+6]):
                res += 1
    print(res)


for _ in range(int(input())):
    Solve()
