#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll Calc(vector<ll> a, ll m)
{
    sort(a.begin(), a.end());
    a.push_back(m + 1);
    ll res = 0;
    for (ll i = 1; i < a.size(); i++)
        res += max(0LL, a[i] - a[i - 1] - 2);
    return res;
}
int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    map<ll, vector<ll>> key;
    while (k--)
    {
        ll ai, bi;
        cin >> ai >> bi;
        if (key[ai].empty())
        {
            key[ai].push_back(0LL);
            key[ai].push_back(bi);
        }
        else
            key[ai].push_back(bi);
    }
    ll ans = 0;
    for (auto x : key)
        ans += Calc(x.second, m);
    ll len = key.size();
    ans += ((n - len) * (m - 1));
    cout << ans;
    return 0;
}
