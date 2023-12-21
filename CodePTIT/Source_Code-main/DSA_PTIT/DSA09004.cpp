#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
bool vis[MAX];
void DFS(int s)
{
    vis[s] = true;
    cout << s << " ";
    for (int i = 0; i < adj[s].size(); i++)
    {
        if (!vis[adj[s][i]])
            DFS(adj[s][i]);
    }
}
void Solve()
{
    for (int i = 0; i < MAX; i++)
        adj[i].clear();
    memset(vis, false, sizeof(vis));
    int V, E, s;
    cin >> V >> E >> s;
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(s);
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
