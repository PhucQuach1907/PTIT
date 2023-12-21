#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    vector<ll> dp(55);
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (ll i = 3; i <= 50; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}
