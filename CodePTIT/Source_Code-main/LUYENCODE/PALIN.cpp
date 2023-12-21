#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int dp[n][n];
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i + 1 == j)
                dp[i][j] = (s[i] == s[j] ? 2 : 1);
            else
                dp[i][j] = (s[i] == s[j] ? dp[i + 1][j - 1] + 2 : max(dp[i][j - 1], dp[i + 1][j]));
        }
    }
    cout << dp[0][n - 1];
    return 0;
}
