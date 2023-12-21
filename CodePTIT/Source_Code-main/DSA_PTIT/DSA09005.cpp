#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e3 + 5;
vector<int> adj[MAX];
bool vis[MAX];
void BFS(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int temp = q.front();
        cout << temp << " ";
        q.pop();
        for (int i = 0; i < adj[temp].size(); i++)
        {
            if (!vis[adj[temp][i]])
            {
                vis[adj[temp][i]] = true;
                q.push(adj[temp][i]);
            }
        }
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
    BFS(s);
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
