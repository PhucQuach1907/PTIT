from math import log2

nmc = "0123456789ABCDEF"


def Solve():
    b = int(input())
    bin = input()
    tmp = int(log2(b))
    while(len(bin) % tmp != 0):
        bin = "0"+bin
    res = ""
    for i in range(0, len(bin), tmp):
        res += nmc[int(bin[i:i+tmp:1], 2)]
    print(res)


for _ in range(int(input())):
    Solve()
