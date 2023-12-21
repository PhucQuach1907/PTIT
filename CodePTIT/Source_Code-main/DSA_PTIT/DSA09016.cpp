#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<int> adj[1005];
bool vis[1005];
int target, parent[1005];
bool ok;
void Clear()
{
    for (int i = 0; i < 1005; i++)
        adj[i].clear();
}
void DFS(int cur)
{
    if (ok)
        return;
    vis[cur] = true;
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            parent[x] = cur;
            DFS(x);
        }
        else if (parent[cur] != x && x == target)
        {
            ok = 1;
            return;
        }
    }
}
void Solve()
{
    Clear();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));
        ok = 0;
        target = i;
        DFS(target);
        if (ok)
            break;
    }
    cout << (ok ? "YES\n" : "NO\n");
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
