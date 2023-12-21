#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    s1 = "-" + s1, s2 = "-" + s2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            dp[i][j] = (s1[i] == s2[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]));
    }
    cout << dp[n][m] << "\n";
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
