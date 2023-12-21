#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
int disc[MAX], low[MAX], parent[MAX], cnt;
bool vis[MAX], isAP[MAX];
void Clear()
{
    for (int i = 0; i < MAX; i++)
        adj[i].clear();
    memset(disc, 0, sizeof(disc));
    memset(low, 0, sizeof(low));
    memset(parent, -1, sizeof(parent));
    memset(vis, 0, sizeof(vis));
    memset(isAP, false, sizeof(isAP));
    cnt = 0;
}
void DFS(int u)
{
    vis[u] = true;
    disc[u] = low[u] = ++cnt;
    int child = 0;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            child++;
            parent[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }
        else if (v != parent[u])
            low[u] = min(low[u], disc[v]);
    }
    if (parent[u] == -1 && child > 1)
        isAP[u] = true;
}
void Solve()
{
    Clear();
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
            DFS(i);
    }
    for (int i = 1; i <= V; i++)
    {
        if (isAP[i])
            cout << i << " ";
    }
    cout << "\n";
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
