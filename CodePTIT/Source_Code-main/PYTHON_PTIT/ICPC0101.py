n = int(input())
tmp = list(map(int, input().split()))
arr = []
for i in range(0, n):
    num = tmp[i]
    if (len(arr) == 0):
        arr.append(num)
    else:
        if ((arr[-1]+num) % 2 == 0):
            arr.pop()
        else:
            arr.append(num)
print(len(arr))
