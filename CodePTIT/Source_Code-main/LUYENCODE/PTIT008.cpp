#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    int res = -1;
    res = max(res, a.front().second + a.front().first - 1);
    res = max(res, a.back().second + n - a.back().first);
    for (int i = 1; i < m; i++)
    {
        int li = a[i - 1].first, ri = a[i].first;
        int lh = a[i - 1].second, rh = a[i].second;
        if (rh > lh + ri - li || rh < lh - (ri - li))
        {
            cout << -1;
            return 0;
        }
        int mx = max(lh, rh), mn = min(lh, rh), remain = ri - li - 1;
        remain -= (mx - mn);
        res = max(res, mx + ((remain + 1) / 2));
    }
    cout << res;
    return 0;
}
