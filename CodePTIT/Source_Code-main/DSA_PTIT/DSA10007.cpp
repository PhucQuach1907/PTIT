#include <bits/stdc++.h>
using namespace std;
void Solve()
{
    vector<pair<int, int>> BFS_ans;
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
    queue<int> q;
    q.push(start);
    vis[start] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto x : adj[cur])
        {
            if (!vis[x])
            {
                vis[x] = true;
                BFS_ans.push_back({cur, x});
                q.push(x);
            }
        }
    }
    if (BFS_ans.size() < V - 1)
        cout << -1 << "\n";
    else
    {
        for (auto x : BFS_ans)
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
