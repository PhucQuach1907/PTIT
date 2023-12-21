#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll dp[30][30];
    for (int i = 0; i <= 25; i++)
        dp[i][0] = dp[0][i] = 1;
    dp[0][0] = 0;
    for (int i = 1; i <= 25; i++)
    {
        for (int j = 1; j <= 25; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        cout << dp[n][m] << "\n";
    }
    return 0;
}
