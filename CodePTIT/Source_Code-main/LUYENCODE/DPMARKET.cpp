#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> rent(n + 1), cost(m + 1), dp(n + 1, INT_MAX);
    for (ll i = 1; i <= n; i++)
        cin >> rent[i];
    sort(rent.begin() + 1, rent.end());
    for (ll i = 1; i <= m; i++)
        cin >> cost[i];
    for (ll i = m - 1; i > 0; i--)
        cost[i] = min(cost[i], cost[i + 1]);
    dp[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j++)
        {
            ll len = rent[j] - rent[i] + 1;
            dp[j] = min(dp[j], dp[i - 1] + cost[len]);
        }
    }
    cout << dp[n];
    return 0;
}
