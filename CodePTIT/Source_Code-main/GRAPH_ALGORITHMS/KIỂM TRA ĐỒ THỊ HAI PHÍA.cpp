#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool ok;
void DFS(vector<int> adj[], vector<int> &color, int cur)
{
    if (!ok)
        return;
    for (auto x : adj[cur])
    {
        if (color[x] == -1)
        {
            color[x] = !color[cur];
            DFS(adj, color, x);
        }
        else if (color[x] == color[cur])
        {
            ok = false;
            return;
        }
    }
}
int main()
{
    ok = 1;
    int n, m;
    cout << "Nhap so dinh cua do thi: ";
    cin >> n;
    cout << "Nhap so canh cua do thi: ";
    cin >> m;
    vector<int> adj[n + 1];
    cout << "Nhap cac canh cua do thi:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            DFS(adj, color, i);
        }
    }
    string exist = (ok ? "CO\n" : "KHONG\n");
    cout << "DO THI " << exist << " LA DO THI HAI PHIA!";
    return 0;
}
