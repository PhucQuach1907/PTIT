#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool ok;
void DFS(vector<int> adj[], vector<int> &color, int cur)
{
    if (!ok)
        return;
    for (auto x : adj[cur])
    {
        if (color[x] == -1)
        {
            color[x] = !color[cur];
            DFS(adj, color, x);
        }
        else if (color[x] == color[cur])
        {
            ok = false;
            return;
        }
    }
}
void Solve()
{
    ok = 1;
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
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            DFS(adj, color, i);
        }
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
