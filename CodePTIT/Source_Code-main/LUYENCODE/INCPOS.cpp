#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a)
        cin >> x;
    vector<ll> diff(n + 1);
    ll res = 0;
    for (ll i = 1; i < n; i++)
    {
        diff[i] = a[i - 1] - a[i];
        res += (diff[i] > 0);
    }
    while (q--)
    {
        ll l, r, x;
        cin >> l >> r >> x;
        if (l > 1)
        {
            res -= (diff[l - 1] > 0);
            diff[l - 1] -= x;
            res += (diff[l - 1] > 0);
        }
        if (r < n)
        {
            res -= (diff[r] > 0);
            diff[r] += x;
            res += (diff[r] > 0);
        }
        cout << res << "\n";
    }
    return 0;
}
