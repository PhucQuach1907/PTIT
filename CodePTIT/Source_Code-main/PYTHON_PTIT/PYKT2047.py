from bisect import bisect_left
import sys


if __name__ == "__main__":
    data = []
    for line in sys.stdin:
        for x in line.split():
            data.append(int(x))
    idx = 1
    for _ in range(data[0]):
        n = data[idx]
        idx += 1
        pos, h, pref = [-1]*(n+1), [-1]*(n+1), [0]*(n+1)
        pos = [-1]+data[idx:idx+n]
        idx += n
        h = [-1]+data[idx:idx+n]
        idx += n
        for i in range(1, n+1):
            pref[i] = pref[i-1]+h[i]
        larger, stk = [-1]*(n+1), []
        for i in range(n, 0, -1):
            while stk and h[stk[-1]] <= h[i]:
                larger[stk.pop()] = i
            stk.append(i)
        while stk:
            larger[stk.pop()] = 0
        query = [0]*(n+1)
        for i in range(1, n+1):
            query[i] = query[larger[i]] + h[i] * (pos[i] - pos[larger[i]] - 1)
            l, r = larger[i] + 1, i - 1
            query[i] -= pref[r]-pref[l-1] if l <= r else 0
        q = data[idx]
        idx += 1
        for _ in range(q):
            k = data[idx]
            idx += 1
            p = bisect_left(query, k, 1, len(query))
            print(p-1)
