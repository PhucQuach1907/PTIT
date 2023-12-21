fibo = [1, 1]
for i in range(1, 95):
    fibo.append(fibo[-1]+fibo[-2])


def Solve():
    a, b = map(int, input().split())
    print(" ".join(map(str, fibo[a-1:b:1])))


for i in range(0, int(input())):
    Solve()
