import math


def Solve():
    n = int(input())
    arr = map(int, list(str(n)))
    sum = 0
    for x in arr:
        sum += math.factorial(x)
    print("Yes" if n == sum else "No")


for i in range(0, int(input())):
    Solve()
