def Check(n):
    sum = n % 10
    prev = n % 10
    n //= 10
    while n:
        cur = n % 10
        sum += n % 10
        if (abs(cur-prev) != 2):
            return False
        prev = cur
        n //= 10
    return (sum % 10 == 0)


def Solve():
    n = int(input())
    print("YES" if Check(n) else "NO")


for i in range(0, int(input())):
    Solve()
