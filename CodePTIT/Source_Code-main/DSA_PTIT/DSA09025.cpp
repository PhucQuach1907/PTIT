#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
bool vis[MAX];
int front[MAX];
void DFS(int s, int e)
{
    if (vis[e])
        return;
    vis[s] = true;
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!vis[adj[s][i]])
        {
            front[adj[s][i]] = s;
            DFS(adj[s][i], e);
        }
    }
}
void Trace(int s, int e)
{
    if (!vis[e])
    {
        cout << -1 << "\n";
        return;
    }
    vector<int> road;
    while (e != s)
    {
        road.push_back(e);
        e = front[e];
    }
    road.push_back(s);
    reverse(road.begin(), road.end());
    for (auto x : road)
        cout << x << " ";
    cout << "\n";
}
void Solve()
{
    for (int i = 0; i < MAX; i++)
        adj[i].clear();
    memset(vis, false, sizeof(vis));
    int V, E, s, e;
    cin >> V >> E >> s >> e;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    DFS(s, e);
    Trace(s, e);
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
