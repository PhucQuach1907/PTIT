#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    ll ans = 0;
    for (ll i = 0; i < k; i++)
        ans += a[i];
    ll tmp = ans;
    for (ll i = k; i < n; i++)
    {
        tmp -= a[i - k];
        tmp += a[i];
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
