from queue import Queue


def Solve():
    n = int(input())
    q = Queue()
    q.put("1")
    q.put("2")
    res = []
    while (not q.empty()):
        cur = q.get()
        if len(res) >= n:
            break
        if cur.count("2") > len(cur)//2:
            res.append(cur)
        q.put(cur+"0")
        q.put(cur+"1")
        q.put(cur+"2")
    print(" ".join(res))


for i in range(int(input())):
    Solve()
