#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<int> adj[1005];
bool vis[1005];
void DFS(int u)
{
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (!vis[adj[u][i]])
            DFS(adj[u][i]);
    }
}
void Solve()
{
    for (int i = 0; i < 1005; i++)
        adj[i].clear();
    memset(vis, false, sizeof(vis));
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            res++;
            DFS(i);
        }
    }
    cout << res << "\n";
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
