#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<vector<int>> ans;
vector<int> path(1005);
void DFS(int cur, int idx, vector<int> adj[])
{
    path[idx] = cur;
    if (adj[cur].size() == 0)
    {
        ans.push_back({path.begin(), path.begin() + idx + 1});
        return;
    }
    for (auto x : adj[cur])
        DFS(x, idx + 1, adj);
}
bool cmp(vector<int> a, vector<int> b)
{
    return a.back() < b.back();
}
void Solve()
{
    ans.clear();
    int n;
    cin >> n;
    vector<int> adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    DFS(1, 0, adj);
    sort(ans.begin(), ans.end(), cmp);
    for (auto x : ans)
    {
        for (int i = 0; i < (int)x.size(); i++)
            cout << x[i] << " \n"[i == (int)x.size() - 1];
    }
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
