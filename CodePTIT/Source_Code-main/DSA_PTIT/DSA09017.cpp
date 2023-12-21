#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
bool res, vis[MAX];
void Clear()
{
    memset(vis, false, sizeof(vis));
    res = true;
    for (int i = 1; i < MAX; i++)
        adj[i].clear();
}
void DFS(int x)
{
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (!vis[adj[x][i]])
        {
            vis[x] = true;
            DFS(adj[x][i]);
        }
        else
            res = false;
    }
}
void Solve()
{
    Clear();
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            DFS(i);
    }
    cout << (res ? "YES\n" : "NO\n");
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
