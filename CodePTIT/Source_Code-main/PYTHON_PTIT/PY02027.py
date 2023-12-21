import re
arr = []
for i in range(int(input())):
    tmp = re.split(r'[A-Za-z]', input())
    for x in tmp:
        if len(x) > 0:
            arr.append(int(x))
arr.sort()
for x in arr:
    print(x)
