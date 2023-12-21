#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool vis[1005];
vector<int> adj[1005];
vector<vector<int>> res;
vector<int> v;
void DFS(int x)
{
    vis[x] = true;
    v.push_back(x);
    for (auto X : adj[x])
    {
        if (!vis[X])
        {
            vis[X] = true;
            DFS(X);
        }
    }
}
int main()
{
    memset(vis, false, sizeof(vis));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            DFS(i);
            sort(v.begin(), v.end());
            res.push_back(v);
            v.clear();
        }
    }
    cout << res.size() << "\n";
    for (auto arr : res)
    {
        cout << arr.size() << " ";
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " \n"[i == arr.size() - 1];
    }
    return 0;
}
