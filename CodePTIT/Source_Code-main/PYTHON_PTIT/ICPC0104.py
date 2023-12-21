import re


def Solve():
    print(min(list(map(int, list(filter(lambda e: (e != ''), re.split(r'[A-Za-z]', input())))))))


for t in range(int(input())):
    Solve()
