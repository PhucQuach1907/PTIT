n = int(input())
res = []


def Check(str):
    a, b, c = str.count("A"), str.count("B"), str.count("C")
    if a == 0 or b == 0 or c == 0:
        return False
    if (a <= b and b <= c):
        return True
    return False


def Try(len, str):
    if (len > n):
        return
    if (Check(str)):
        res.append(str)
    Try(len+1, str+"A")
    Try(len+1, str+"B")
    Try(len+1, str+"C")


Try(0, "")
res.sort(key=lambda x: (len(x), x))
for x in res:
    print(x)
