#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ll a[1005][1005], dp[1005][1005];
int main()
{
    ll n, m;
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    dp[1][1] = a[1][1];
    for (ll i = 2; i <= m; i++)
        dp[1][i] = (a[1][i] == -1 || dp[1][i - 1] == -1 ? -1 : dp[1][i - 1] + a[1][i]);
    for (ll i = 2; i <= n; i++)
        dp[i][1] = (a[i][1] == -1 || dp[i - 1][1] == -1 ? -1 : dp[i - 1][1] + a[i][1]);
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 2; j <= m; j++)
        {
            if (a[i][j] == -1 || (dp[i - 1][j] == -1 && dp[i][j - 1] == -1))
                dp[i][j] = -1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
        }
    }
    cout << dp[n][m];
    return 0;
}
