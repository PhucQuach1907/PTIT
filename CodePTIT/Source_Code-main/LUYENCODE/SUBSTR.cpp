#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    int dp[n + 1][m + 1];
    s1 = "-" + s1, s2 = "-" + s2;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            dp[i][j] = (s1[i] == s2[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]));
    }
    cout << dp[n][m];
}
int main()
{
    Solve();
    return 0;
}
