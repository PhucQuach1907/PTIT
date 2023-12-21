#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int pref[n + 1];
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i - 1] + a[i];
    int dp[6800][2];
    dp[1][1] = a[1];
    dp[1][0] = dp[0][0] = dp[0][1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        for (int j = 1; j < k; j++)
        {
            if (i >= j)
                dp[i][1] = max(dp[i][1], pref[i] - pref[i - j] + dp[i - j][0]);
        }
    }
    cout << max(dp[n][0], dp[n][1]);
    return 0;
}
