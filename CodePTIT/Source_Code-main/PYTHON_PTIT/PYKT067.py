import itertools


def Solve():
    num = [i for i in range(1, int(input())+1)]
    res = []
    for x in itertools.permutations(num):
        res.append("".join(map(str, x)))
    print(len(res))
    for i in range(len(res)-1, -1, -1):
        print(res[i], end=" ")
    print()


for _ in range(int(input())):
    Solve()
