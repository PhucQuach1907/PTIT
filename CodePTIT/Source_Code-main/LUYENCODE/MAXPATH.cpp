#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int a[105][105], dp[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
                dp[i][j] = max({dp[i][j - 1], dp[i + 1][j - 1]}) + a[i][j];
            else if (i == n)
                dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1]}) + a[i][j];
            else
                dp[i][j] = max({dp[i][j - 1], dp[i - 1][j - 1], dp[i + 1][j - 1]}) + a[i][j];
        }
    }
    int res = INT_MIN;
    for (int i = 1; i <= n; i++)
        res = max(res, dp[i][m]);
    cout << res;
    return 0;
}