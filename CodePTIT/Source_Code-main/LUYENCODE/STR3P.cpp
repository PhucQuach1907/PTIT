#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
int main()
{
    ll n;
    scanf("%lld", &n);
    ll dp[n + 1][3]; //dp[i][j]: số xâu tam phân có độ dài i và kết thúc bằng j
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (ll i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
    }
    ll ans = (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
    printf("%lld", ans);
    return 0;
}
