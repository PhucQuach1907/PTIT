import math


def Solve():
    n = int(input())
    arr = ["1"]
    cnt = 0
    while n % 2 == 0:
        n //= 2
        cnt += 1
    if (cnt > 0):
        arr.append("2^"+str(cnt))
    for i in range(3, int(math.sqrt(n))+1, 2):
        if n % i == 0:
            cnt = 0
            while n % i == 0:
                n //= i
                cnt += 1
            arr.append(str(i)+"^"+str(cnt))
    if n > 1:
        arr.append(str(n)+"^1")
    print(" * ".join(arr))


for i in range(0, int(input())):
    Solve()
