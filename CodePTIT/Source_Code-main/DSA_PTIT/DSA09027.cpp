#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void DFS(vector<int> adj[], vector<bool> &vis, int cur, int t)
{
    if (vis[t])
        return;
    vis[cur] = true;
    for (auto x : adj[cur])
    {
        if (!vis[x])
            DFS(adj, vis, x, t);
    }
}
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        vector<bool> vis(n + 1, false);
        DFS(adj, vis, s, t);
        cout << (vis[t] ? "YES\n" : "NO\n");
    }
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
