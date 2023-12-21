res = 0


def Processing(n):
    global res
    s = str(n)
    sum = 0
    if (len(s) == 1):
        return
    for x in s:
        sum += ord(x)-ord("0")
    res += 1
    Processing(sum)


n = int(input())
Processing(n)
print(res)
