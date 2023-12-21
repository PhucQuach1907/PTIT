#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<bool> vis(n + 1, false);
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
        for (auto x : adj[i])
        {
            if (vis[x])
                continue;
            for (auto y : adj[x])
            {
                if (!binary_search(adj[i].begin(), adj[i].end(), y) && y != i)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
        vis[i] = true;
    }
    cout << "YES\n";
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
