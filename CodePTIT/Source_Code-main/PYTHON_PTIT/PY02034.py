from collections import defaultdict
arr = list(input())
while len(arr) & 1:
    arr.pop()
s = "".join(arr)
res = []
cnt = defaultdict(int)
for i in range(0, len(s), 2):
    if s[i:i+2] not in res:
        res.append(s[i:i+2])
    cnt[s[i:i+2]] += 1
for x in res:
    print(x, cnt[x])
