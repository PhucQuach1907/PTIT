#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
void Solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= max(0LL, i - k); j--)
            dp[i] = (dp[i] + dp[j]) % MOD;
    }
    cout << dp[n] << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
