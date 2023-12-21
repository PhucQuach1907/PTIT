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
    sort(a.rbegin(), a.rend());
    while (a.back() == 0)
        a.pop_back();
    reverse(a.begin(), a.end());
    n = a.size();
    ll ans = 0;
    for (ll i = n - 1; i > 0; i--)
    {
        ll l = 0, r = i - 1;
        while (l < r)
        {
            if (a[l] + a[r] > a[i])
            {
                ans += (r - l);
                r--;
            }
            else
                l++;
        }
    }
    cout << ans;
    return 0;
}
