#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void calcDis(vector<int> adj[], vector<int> &dis, int cur, int level)
{
    dis[cur] = level;
    if (adj[cur].size() == 0)
        return;
    for (auto x : adj[cur])
        calcDis(adj, dis, x, level + 1);
}
int LCA(int u, int v, vector<int> parent, vector<int> depth)
{
    while (depth[u] != depth[v])
    {
        if (depth[u] > depth[v])
            u = parent[u];
        else
            v = parent[v];
    }
    while (u != v)
    {
        u = parent[u];
        v = parent[v];
    }
    return u;
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    vector<int> parent(n + 1);
    vector<int> dis(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        parent[v] = u;
    }
    calcDis(adj, dis, 1, 0);
    int q;
    cin >> q;
    while (q--)
    {
        int s, t;
        cin >> s >> t;
        cout << (dis[s] + dis[t] - 2 * dis[LCA(s, t, parent, dis)]) << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
