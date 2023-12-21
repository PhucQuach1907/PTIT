isPrime = [True for i in range(32000)]
primeList = []


def Sieve():
    isPrime[0] = isPrime[1] = False
    for i in range(2, 16001):
        if isPrime[i]:
            isPrime[2*i:32000:i] = [False for j in range(2*i, 32000, i)]
    for i in range(32000):
        if (isPrime[i]):
            primeList.append(i)


Sieve()

numberHasNineDivisors = [2**8, 3**8, 5**8, 7**8, 11**8]
for i in range(len(primeList)):
    tmp1 = primeList[i]**2
    if tmp1 * primeList[i+1]**2 > int(1e9):
        break
    for j in range(i+1, len(primeList)):
        tmp2 = tmp1 * primeList[j]**2
        if (tmp2 < int(1e9)):
            numberHasNineDivisors.append(tmp2)
        else:
            break


def Solve():
    n = int(input())
    res = 0
    for i in range(len(numberHasNineDivisors)):
        if numberHasNineDivisors[i] <= n:
            res += 1
    print(res)


Solve()
