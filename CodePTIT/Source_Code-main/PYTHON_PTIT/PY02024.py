def digitProduct(n):
    product = 1
    while n:
        product *= n % 10
        n //= 10
    return product


def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort(key=lambda x: (digitProduct(x), x))
    print(" ".join(map(str, arr)))


for i in range(int(input())):
    Solve()
