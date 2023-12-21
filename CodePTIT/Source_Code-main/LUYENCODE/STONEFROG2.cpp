#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), dp(n, 0);
    for (auto &x : a)
        cin >> x;
    for (ll i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + abs(a[i] - a[i - 1]);
        for (ll j = i - 2; j >= max(0LL, i - k); j--)
        {
            if (i - k >= 0)
                dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
        }
    }
    cout << dp[n - 1];
    return 0;
}
