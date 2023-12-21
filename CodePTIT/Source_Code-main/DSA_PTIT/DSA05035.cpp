#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
int main()
{
    vector<vector<ll>> dp(105, vector<ll>(15, 0));
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = j; k >= 0; k--)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < 10; i++)
            ans = (ans + dp[n][i]) % MOD;
        cout << ans << "\n";
    }
    return 0;
}
