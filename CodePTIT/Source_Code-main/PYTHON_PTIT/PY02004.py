n = int(input())
arr = list(map(int, input().split()))
res = 0
for i in range(0, n):
    res += 1 if arr[i] != arr[i-1] else 0
print(res)
