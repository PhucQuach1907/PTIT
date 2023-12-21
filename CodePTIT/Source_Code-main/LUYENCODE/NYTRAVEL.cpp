#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MAX = 1e5 + 5;
bool vis[MAX];
vector<int> adj[MAX];
int cnt = 0;
void DFS(int x)
{
    cnt++;
    vis[x] = true;
    for (auto tmp : adj[x])
    {
        if (!vis[tmp])
            DFS(tmp);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    vector<int> v;
    DFS(1);
    int res = cnt;
    cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
            DFS(i);
        v.push_back(cnt);
        cnt = 0;
    }
    sort(v.begin(), v.end());
    cout << res + v.back();
    return 0;
}
