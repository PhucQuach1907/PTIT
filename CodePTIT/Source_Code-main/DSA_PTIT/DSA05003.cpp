#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m, p;
    cin >> n >> m >> p;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int dp[n + 1][m + 1][p + 1];
    s1 = "-" + s1, s2 = "-" + s2, s3 = "-" + s3;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 1; k <= p; k++)
                dp[i][j][k] = (s1[i] == s2[j] && s2[j] == s3[k] ? dp[i - 1][j - 1][k - 1] + 1 : max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]}));
        }
    }
    cout << dp[n][m][p] << "\n";
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
