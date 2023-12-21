#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    vector<int> adj[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j])
                adj[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end());
        for (auto x : adj[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
