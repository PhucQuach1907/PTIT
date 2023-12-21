#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    set<ll> r, c;
    for (ll i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        r.insert(x), c.insert(y);
    }
    ll rd = n - r.size(), cd = m - c.size();
    ll ans = n * m - (rd * n + cd * m - (rd * cd));
    cout << ans;
    return 0;
}
