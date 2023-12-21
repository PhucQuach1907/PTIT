#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
int main()
{
    vector<vector<ll>> dp(105, vector<ll>(905));
    dp[0][0] = 1;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 900; j++)
        {
            for (int dig = 0; dig < 10; dig++)
            {
                if (j >= dig)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - dig]) % MOD;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k > 900)
            cout << 0 << "\n";
        else
            cout << dp[n][k] << "\n";
    }
    return 0;
}
