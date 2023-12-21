#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    string s;
    cin >> s;
    int n = s.size();
    s = "-" + s;
    int dp[n + 5][n + 5];
    for (int i = 1; i <= n; i++)
        dp[i][i] = 0;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (i + 1 == j)
                dp[i][j] = (s[i] == s[j] ? 0 : 1);
            else
                dp[i][j] = (s[i] == s[j] ? dp[i + 1][j - 1] : min(dp[i][j - 1], dp[i + 1][j]) + 1);
        }
    }
    cout << dp[1][n] << "\n";
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
