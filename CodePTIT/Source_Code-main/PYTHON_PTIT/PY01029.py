import math


def Solve():
    str = input()
    print("YES" if math.gcd(int(str), int(str[::-1])) == 1 else "NO")


for i in range(0, int(input())):
    Solve()
