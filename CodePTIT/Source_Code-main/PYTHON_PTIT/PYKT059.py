n, m, nmc = map(int, input().split())
adj = [[] for i in range(n+1)]
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

vis = [False]*(n+1)


def DFS(u):
    vis[u] = True
    for x in adj[u]:
        if not vis[x]:
            DFS(x)


DFS(nmc)
res = 0
ok = False
for i in range(1, n+1):
    if not vis[i]:
        print(i)
        ok = True
if not ok:
    print(0)
