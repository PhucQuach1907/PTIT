#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> DFS_ans;
void DFS(vector<int> adj[], vector<bool> &vis, int cur)
{
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            vis[x] = true;
            DFS_ans.push_back({cur, x});
            DFS(adj, vis, x);
        }
    }
}
void Solve()
{
    DFS_ans.clear();
    int V, E, start;
    cin >> V >> E >> start;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(V + 1, false);
    vis[start] = true;
    DFS(adj, vis, start);
    if (DFS_ans.size() < V - 1)
        cout << -1 << "\n";
    else
    {
        for (auto x : DFS_ans)
            cout << x.first << " " << x.second << "\n";
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
