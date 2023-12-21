#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> DFS_ans;
void DFS(vector<int> adj[], vector<bool> &vis, int cur)
{
    for (auto x : adj[cur])
    {
        if (!vis[x])
        {
            vis[x] = true;
            DFS_ans.push_back({cur, x});
            DFS(adj, vis, x);
        }
    }
}
int main()
{
    int V, E, start;
    cout << "Nhap so dinh: ";
    cin >> V;
    cout << "Nhap so canh: ";
    cin >> E;
    cout << "Nhap dinh goc: ";
    cin >> start;
    vector<int> adj[V + 1];
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(V + 1, false);
    vis[start] = true;
    DFS(adj, vis, start);
    if (DFS_ans.size() < V - 1)
        cout << "KHONG TON TAI CAY KHUNG VOI GOC LA DINH " << start;
    else
    {
        cout << "CAY KHUNG CUA DO THI VOI GOC LA DINH " << start << " LA:\n";
        for (auto x : DFS_ans)
            cout << x.first << " " << x.second << "\n";
    }
    return 0;
}
