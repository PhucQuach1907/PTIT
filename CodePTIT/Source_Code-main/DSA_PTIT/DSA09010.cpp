#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 1];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= V; i++)
    {
        if (adj[i].size() == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
