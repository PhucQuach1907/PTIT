import math
from collections import defaultdict
MAX = 1000005
isPrime = [True for i in range(MAX)]
isPrime[0] = isPrime[1] = False
for i in range(2, MAX//2 + 1):
    if isPrime[i]:
        for j in range(i*2, MAX, i):
            isPrime[j] = False
n = int(input())
arr = list(map(int, input().split()))
cnt = defaultdict(int)
for x in arr:
    cnt[x] += 1

for x in arr:
    if isPrime[x] and cnt[x] > 0:
        print(x, cnt[x])
        cnt[x] = 0
