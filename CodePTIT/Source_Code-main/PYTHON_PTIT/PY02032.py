arr = list(input())
while len(arr) & 1:
    arr.pop()
s = "".join(arr)
res = set()
for i in range(0, len(s), 2):
    res.add(s[i:i+2])
print(" ".join(sorted(res)))
