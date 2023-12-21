#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool vis[105];
vector<int> adj[105];
void BFS(int x)
{
    queue<int> q;
    q.push(x);
    vis[x] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << "\n";
        for (auto v : adj[temp])
        {
            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            BFS(i);
    }
    return 0;
}
