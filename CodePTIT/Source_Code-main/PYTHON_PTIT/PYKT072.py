import sys
if __name__ == "__main__":
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(input())
    res = int(10**9)
    for i in arr:
        tmp = i*2
        step = 0
        for j in arr:
            if j != i:
                idx = tmp.find(j)
                if idx == -1:
                    print(-1)
                    sys.exit(0)
                else:
                    step += len(i)-idx
        res = min(res, step)
    print(res)
