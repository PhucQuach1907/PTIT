#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<int> adj[1005];
bool vis[1005];
int parent[1005];
void Clear()
{
    for (int i = 0; i < 1005; i++)
        adj[i].clear();
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
}
void DFS(int cur)
{
    if (parent[1] != -1)
        return;
    vis[cur] = true;
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            parent[x] = cur;
            DFS(x);
        }
        else if (x == 1 && parent[cur] != x)
        {
            parent[1] = cur;
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
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    DFS(1);
    if (parent[1] == -1)
        cout << "NO\n";
    else
    {
        vector<int> ans;
        int c = parent[1];
        ans.push_back(1);
        while (c != 1)
        {
            ans.push_back(c);
            c = parent[c];
        }
        ans.push_back(1);
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << " ";
        cout << "\n";
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
