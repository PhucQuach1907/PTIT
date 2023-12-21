from collections import defaultdict
import sys
n = int(input())
cnt = defaultdict(int)
mx = -1
for line in sys.stdin:
    for element in line.split():
        mx = max(mx, int(element))
        cnt[int(element)] += 1
ok = False
for i in range(1, mx+1):
    if cnt[i] == 0:
        print(i)
        ok = True
if not ok:
    print("Excellent!")
