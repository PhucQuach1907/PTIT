n = int(input())
arr = list(map(int, input().split()))
mn = min(arr)
ans = 10**18
for i in range(1, mn+1):
    x, ok = 0, True
    for j in range(0, n):
        tmp1 = arr[j] * 1.0 / i
        tmp2 = arr[j] * 1.0 / (i + 1)
        tmp = int(tmp2) + 1
        if tmp <= tmp1:
            x += tmp
        else:
            ok = False
            break
    if ok:
        ans = min(ans, x)
print(ans)
