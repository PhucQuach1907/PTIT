#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
        a[i].first = a[i].second = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].first++;
        a[v].second++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i].first != a[i].second)
        {
            cout << 0 << "\n";
            return;
        }
    }
    cout << 1 << "\n";
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
