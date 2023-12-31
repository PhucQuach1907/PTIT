import re
from collections import defaultdict
from functools import cmp_to_key


def compare(x, y):
    if x[1] != y[1]:
        return y[1]-x[1]
    if x[0] > y[0]:
        return 1
    return -1


def removeDigit(s):
    res = ""
    for i in range(len(s)):
        if not s[i].isdigit():
            res += s[i]
    return res


n = int(input())
cnt = defaultdict(int)
for i in range(n):
    arr = re.split(r'\W', input().lower())
    for word in arr:
        tmp = removeDigit(word)
        if len(tmp) > 0:
            cnt[tmp] += 1
nmc = list(cnt.items())
nmc.sort(key=cmp_to_key(compare))
for x in nmc:
    if not x[0].isdigit():
        print(x[0], x[1])
