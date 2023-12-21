def kthCharacter(order, pos):
    if pos == 1 << order:
        return chr(order+65)
    if pos > 1 << order:
        return kthCharacter(order-1, pos-(1 << order))
    return kthCharacter(order-1, pos)


def Solve():
    n, k = map(int, input().split())
    print(kthCharacter(n, k))


for i in range(int(input())):
    Solve()
