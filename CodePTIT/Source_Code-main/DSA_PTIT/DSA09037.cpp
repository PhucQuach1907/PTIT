#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<int> adj[1005];
bool vis[1005], isExistPath[1005][1005];
int nmc;
void DFS(int cur)
{
    vis[cur] = true;
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            isExistPath[nmc][x] = 1;
            DFS(x);
        }
    }
}
int main()
{
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> pos(k);
    for (auto &x : pos)
        cin >> x;
    memset(isExistPath, false, sizeof(isExistPath));
    for (int i = 1; i <= n; i++)
        isExistPath[i][i] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        isExistPath[u][v] = 1;
    }
    for (int i = 0; i < k; i++)
    {
        memset(vis, false, sizeof(vis));
        nmc = pos[i];
        DFS(nmc);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        bool ok = 1;
        for (int j = 0; j < k; j++)
            ok &= isExistPath[pos[j]][i];
        ans += ok;
    }
    cout << ans;
    return 0;
}
