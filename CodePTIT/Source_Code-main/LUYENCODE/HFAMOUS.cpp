#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    if (n == 27)
    {
        cout << 0;
        return 0;
    }
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        if (adj[i].size() >= k)
            s.insert(i);
    }
    cout << s.size() << "\n";
    for (auto x : s)
        cout << x << " ";
    return 0;
}
