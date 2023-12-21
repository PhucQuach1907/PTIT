#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> Ox, Oy;
    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        Ox.push_back(x);
        Oy.push_back(y);
        a.push_back({x, y});
    }
    sort(Ox.begin(), Ox.end());
    sort(Oy.begin(), Oy.end());
    ll mid = (n & 1 ? n / 2 : n / 2 - 1);
    ll mid_x = Ox[mid], mid_y = Oy[mid];
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        ans += (abs(a[i].first - mid_x) + abs(a[i].second - mid_y));
    cout << ans;
    return 0;
}
