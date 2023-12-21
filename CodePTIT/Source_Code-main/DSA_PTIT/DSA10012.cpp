#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Node
{
    int id, d;
};
void BFS(int i, int V, vector<int> &dis, vector<int> adj[])
{
    vector<bool> vis(V + 1, false);
    queue<Node> q;
    q.push({i, 0});
    vis[i] = true;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        for (auto x : adj[cur.id])
        {
            if (!vis[x])
            {
                vis[x] = true;
                dis[x] = cur.d + 1;
                q.push({x, cur.d + 1});
            }
        }
    }
}
void Solve()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    int cnt = 0, sum = 0;
    for (int i = 1; i <= V; i++)
    {
        vector<int> dis(V + 1, -1);
        BFS(i, V, dis, adj);
        for (int j = 1; j <= V; j++)
        {
            if (i != j)
            {
                if (dis[j] != -1)
                {
                    cnt++;
                    sum += dis[j];
                }
            }
        }
    }
    double res = sum * 1.0 / cnt;
    cout << fixed << setprecision(2) << res << "\n";
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
