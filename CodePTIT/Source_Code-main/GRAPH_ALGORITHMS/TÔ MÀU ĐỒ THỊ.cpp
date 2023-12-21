#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
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
    vector<int> color(n + 1, 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        vis[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            for (auto x : adj[cur])
            {
                if (color[x] == color[cur])
                    color[x]++;
                if (!vis[x])
                {
                    vis[x] = true;
                    q.push(x);
                }
            }
        }
    }
    cout << "Mau cua dinh sau khi to: ";
    for (int i = 1; i <= n; i++)
        cout << color[i] << " ";
    return 0;
}
