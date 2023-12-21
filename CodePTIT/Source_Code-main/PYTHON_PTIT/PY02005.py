n = int(input())
arr = list(map(int, input().split()))
res = 0
for i in range(0, n):
    for j in range(0, i):
        res += 1 if arr[i] < arr[j] else 0
print(res)
