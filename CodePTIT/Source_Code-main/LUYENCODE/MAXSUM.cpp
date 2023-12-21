#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = INT_MIN, tmp = 0;
    for (ll i = 0; i < n; i++)
    {
        tmp = max(a[i], tmp + a[i]);
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
