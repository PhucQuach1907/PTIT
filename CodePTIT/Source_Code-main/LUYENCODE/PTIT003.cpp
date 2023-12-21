#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> q(n - 1);
    for (ll i = 0; i < n - 1; i++)
        cin >> q[i];
    vector<ll> pref(n - 1);
    pref[0] = q[0];
    for (ll i = 1; i < n - 1; i++)
        pref[i] = pref[i - 1] + q[i];
    ll sum = n * (n + 1) / 2;
    ll tmp = accumulate(pref.begin(), pref.end(), 0LL);
    if ((sum - tmp) % n != 0)
    {
        cout << -1;
        return 0;
    }
    ll start = (sum - tmp) / n;
    if (start < 1)
    {
        cout << -1;
        return 0;
    }
    vector<ll> ans(n);
    ans[0] = start;
    for (ll i = 1; i < n; i++)
        ans[i] = ans[i - 1] + q[i - 1];
    for (auto x : ans)
    {
        if (x < 1 || x > n)
        {
            cout << -1;
            return 0;
        }
    }
    for (auto x : ans)
        cout << x << " ";
    return 0;
}
