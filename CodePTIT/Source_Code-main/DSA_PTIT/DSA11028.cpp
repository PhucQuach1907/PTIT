#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int height;
void DFS(int u, int level, vector<int> adj[])
{
    height = max(height, level);
    for (auto x : adj[u])
        DFS(x, level + 1, adj);
}
void Solve()
{
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    height = -1;
    DFS(1, 0, adj);
    cout << height << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
