from collections import defaultdict
arr = list(input())
k = int(input())
while len(arr) & 1:
    arr.pop()
s = "".join(arr)
res = []
cnt = defaultdict(int)
for i in range(0, len(s), 2):
    if s[i:i+2] not in res:
        res.append(s[i:i+2])
    cnt[s[i:i+2]] += 1
res.sort()
ok = False
for x in res:
    if cnt[x] >= k:
        print(x, cnt[x])
        ok = True
if not ok:
    print("NOT FOUND")
