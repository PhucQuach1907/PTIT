#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int odd = 0;
    for (int i = 1; i <= n; i++)
        odd += ((int)adj[i].size() & 1);
    if (odd == 0)
        cout << 2 << "\n";
    else if (odd == 2)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
