#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<ll>> a(n, vector<ll>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    }
    vector<ll> v;
    for (int i = 0; i < n; i++)
    {
        ll pos = 0, neg = 0;
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] < 0)
                neg += abs(a[i][j]);
            else
                pos += a[i][j];
        }
        v.push_back(max(neg, pos));
    }
    sort(v.begin(), v.end());
    ll ans = (v.size() == 1 ? v.back() : v.back() + v[v.size() - 2]);
    printf("%lld", ans);
    return 0;
}
