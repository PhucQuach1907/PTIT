from collections import defaultdict
n = int(input())
arr = list(map(int, input().split()))
cnt = defaultdict(int)
for x in arr:
    cnt[x] += 1
for i in range(1, n+2):
    if cnt[i] == 0:
        print(i)
        break
