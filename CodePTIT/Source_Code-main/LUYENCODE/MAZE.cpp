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
    ll ans = a[0];
    for (ll i = 1; i < n; i++)
    {
        if (ans % a[i] == 0)
            continue;
        ll tmp = ans / a[i];
        ll mid = ans;
        ll l = a[i] * tmp;
        ans += (l + a[i] - mid);
    }
    cout << ans;
    return 0;
}
