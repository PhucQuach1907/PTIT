#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= n; i++)
    {
        if (i + k <= n && !vis[i])
        {
            swap(a[i], a[i + k]);
            vis[i] = vis[i + k] = 1;
        }
    }
    if (count(vis.begin() + 1, vis.end(), 1) != n)
        cout << -1;
    else
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }
    return 0;
}