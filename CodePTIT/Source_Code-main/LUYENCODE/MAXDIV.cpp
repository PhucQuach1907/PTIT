#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Count(ll n)
{
    return (n * (n + 1) / 2);
}
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> pos;
    pos.push_back(-1);
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (x % k == 0)
            pos.push_back(i);
    }
    pos.push_back(n);
    ll ans = 0;
    for (ll i = 0; i < pos.size() - 2; i++)
    {
        ll l = pos[i] + 1, r = pos[i + 2] - 1;
        ans += Count(r - l + 1);
    }
    pos.erase(pos.begin());
    pos.pop_back();
    for (ll i = 1; i < pos.size(); i++)
    {
        ll l = pos[i - 1] + 1, r = pos[i] - 1;
        ans -= Count(r - l + 1);
    }
    cout << ans;
    return 0;
}
