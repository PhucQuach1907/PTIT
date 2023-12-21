#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto x : adj[i])
            {
                if (color[x] == color[cur])
                    color[x]++;
                if (!vis[x])
                {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
    }
    int need = *max_element(color.begin(), color.end());
    cout << (need <= k ? "YES\n" : "NO\n");
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
