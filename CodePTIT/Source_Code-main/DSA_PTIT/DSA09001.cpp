#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int V, E;
    cin >> V >> E;
    vector<int> adj[V + 5];
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
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
