#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void DFS1(int cur, vector<int> adj[], vector<bool> &vis, stack<int> &stk)
{
    vis[cur] = true;
    for (auto x : adj[cur])
    {
        if (!vis[x])
            DFS1(x, adj, vis, stk);
    }
    stk.push(cur);
}
void DFS2(int cur, vector<int> adj[], vector<bool> &vis, vector<int> &connected)
{
    vis[cur] = true;
    connected.push_back(cur);
    for (auto x : adj[cur])
    {
        if (!vis[x])
            DFS2(x, adj, vis, connected);
    }
}
int main()
{
    int n, m;
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    vector<int> adj1[n + 1], adj_rev[n + 1];
    cout << "Nhap so canh cua do thi: ";
    cin >> m;
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj1[u].push_back(v);
        adj_rev[v].push_back(u);
    }
    stack<int> stk;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            DFS1(i, adj1, vis, stk);
    }
    fill(vis.begin(), vis.end(), false);
    int scc = 0;
    vector<vector<int>> ans;
    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();
        if (!vis[cur])
        {
            scc++;
            vector<int> store;
            DFS2(cur, adj_rev, vis, store);
            ans.push_back(store);
        }
    }
    cout << "So thanh phan lien thong manh: " << scc << "\n";
    for (int i = 0; i < int(ans.size()); i++)
    {
        cout << "Thanh phan " << i + 1 << ": ";
        sort(ans[i].begin(), ans[i].end());
        for (auto x : ans[i])
            cout << x << " \n"[x == ans[i].back()];
    }
    return 0;
}
