#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n), suffix(n);
    for (auto &x : a)
        cin >> x;
    suffix.back() = a.back();
    for (ll i = n - 2; i >= 0; i--)
        suffix[i] = suffix[i + 1] + a[i];
    ll ans = 0;
    for (ll i = 0; i < n - 1; i++)
        ans += (a[i] * suffix[i + 1]);
    cout << ans;
    return 0;
}
