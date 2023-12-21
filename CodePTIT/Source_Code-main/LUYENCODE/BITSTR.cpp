#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MOD = 1e6 + 7;
int main()
{
    int n, k;
    cin >> n >> k;
    if (n < k)
    {
        cout << 0;
        return 0;
    }
    int dp[n + 5][k + 5], pw[n + 5];
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = (pw[i - 1] * 2) % MOD;
    dp[0][k] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < k)
            dp[i][k] = 0;
        else if (i == k)
            dp[i][k] = 1;
        else
        {
            int add = (pw[i - k - 1] + MOD - dp[i - k - 1][k]) % MOD;
            dp[i][k] = (2 * dp[i - 1][k] + add) % MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}
