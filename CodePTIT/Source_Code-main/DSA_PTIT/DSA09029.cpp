#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int n, m;
bool ok;
void isHamiltonPath(vector<int> adj[], vector<bool> &vis, int cur, int cnt)
{
    if (ok)
        return;
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            vis[x] = true;
            cnt++;
            if (cnt == n)
            {
                ok = 1;
                return;
            }
            isHamiltonPath(adj, vis, x, cnt);
            vis[x] = false;
            cnt--;
        }
    }
}
void Solve()
{
    cin >> n >> m;
    vector<int> adj[100];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        vector<bool> vis(100, false);
        vis[i] = true;
        ok = 0;
        isHamiltonPath(adj, vis, i, 1);
        if (ok)
        {
            cout << "1\n";
            return;
        }
    }
    cout << "0\n";
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
