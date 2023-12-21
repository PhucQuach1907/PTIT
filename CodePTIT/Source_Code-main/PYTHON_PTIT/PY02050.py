def Solve():
    n = int(input())
    arr = list(map(int, input().split()))
    stk = []
    leftLarger = [-1]*n
    for i in range(n-1, -1, -1):
        while (len(stk) > 0 and arr[i] > arr[stk[-1]]):
            leftLarger[stk[-1]] = i
            stk.pop()
        stk.append(i)
    for i in range(n):
        print(i-leftLarger[i], end=" ")
    print()


for i in range(int(input())):
    Solve()
