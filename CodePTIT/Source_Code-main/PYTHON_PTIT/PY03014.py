def Solve():
    s = input()
    idx, res, stk = 1, [], []
    for x in s:
        if x == "(":
            res.append(idx)
            stk.append(idx)
            idx += 1
        elif x == ")":
            res.append(stk.pop())
    print(" ".join(map(str, res)))


for _ in range(int(input())):
    Solve()
