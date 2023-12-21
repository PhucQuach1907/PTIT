import math
n = int(input())
arr = list(map(int, input().split()))
arr.sort()
res = []
for i in range(0, n):
    for j in range(i+1, n):
        if math.gcd(arr[i], arr[j]) == 1:
            res.append((arr[i], arr[j]))
for x in res:
    print(x[0], x[1])
