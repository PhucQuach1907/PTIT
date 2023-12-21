#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    sort(a.begin(), a.end());
    ll ans = 0;
    for (ll i = 0; i < n - 2; i++)
    {
        for (ll j = i + 1; j < n - 1; j++)
        {
            ll it = lower_bound(a.begin() + j + 1, a.end(), k - a[i] - a[j]) - a.begin();
            ans += (it - j - 1);
        }
    }
    cout << ans << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
