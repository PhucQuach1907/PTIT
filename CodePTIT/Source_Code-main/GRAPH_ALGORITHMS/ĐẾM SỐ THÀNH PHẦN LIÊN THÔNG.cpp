#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
vector<int> adj[1005];
bool vis[1005];
void DFS(int u)
{
    vis[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        if (!vis[adj[u][i]])
            DFS(adj[u][i]);
    }
}
int main()
{
    memset(vis, false, sizeof(vis));
    int V, E;
    cout << "Nhap so dinh: ";
    cin >> V;
    cout << "Nhap so canh: ";
    cin >> E;
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int res = 0;
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
        {
            res++;
            DFS(i);
        }
    }
    cout << "Do thi co " << res << " thanh phan lien thong!";
    return 0;
}
