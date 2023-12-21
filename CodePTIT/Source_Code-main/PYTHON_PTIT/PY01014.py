a, k, n = map(int, input().split())
ans = []
for i in range(k-a % k, n-a+1, k):
    if (a+i <= n):
        ans.append(i)
print(-1 if len(ans) == 0 else " ".join(list(map(str, ans))))
