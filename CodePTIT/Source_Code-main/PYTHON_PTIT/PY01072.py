import itertools
n, k = map(int, input().split())
arr = list(sorted(set(map(int, input().split()))))
for x in itertools.combinations(arr, k):
    print(" ".join(map(str, x)))
