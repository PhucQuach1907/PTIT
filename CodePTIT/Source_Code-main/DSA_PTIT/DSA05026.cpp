#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int C, n;
    cin >> C >> n;
    vector<int> w(n);
    for (auto &x : w)
        cin >> x;
    vector<vector<int>> dp(n, vector<int>(C + 1, 0));
    fill(dp[0].begin() + w[0], dp[0].end(), w[0]);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= w[i])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + w[i]);
        }
    }
    cout << dp[n - 1][C];
    return 0;
}
