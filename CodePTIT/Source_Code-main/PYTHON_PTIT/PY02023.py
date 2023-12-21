def digitSum(n):
    sum = 0
    while n:
        sum += n % 10
        n //= 10
    return sum


def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    arr.sort(key=lambda x: (digitSum(x), x))
    print(" ".join(map(str, arr)))


for i in range(int(input())):
    Solve()
