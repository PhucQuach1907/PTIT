from collections import defaultdict

n, m = map(int, input().split())
arr = list(map(int, input().split()))
cnt = defaultdict(int)
for x in arr:
    cnt[x] += 1
nmc = list(cnt.items())
nmc.sort(key=lambda x: x[1])
first, second = -1, -1
for x in nmc:
    if x[1] > first:
        second = first
        first = x[1]
if second == -1:
    print("NONE")
else:
    for x in arr:
        if cnt[x] == second:
            print(x)
            break
