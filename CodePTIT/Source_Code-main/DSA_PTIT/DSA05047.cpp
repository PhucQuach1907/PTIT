#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    int mx = INT_MIN;
    vector<vector<int>> a(4, vector<int>(n));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    vector<int> mask = {0, 1, 2, 4, 5, 8, 9, 10};
    vector<vector<int>> nmc(n, vector<int>(20, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (mask[j] & (1 << k))
                    nmc[i][mask[j]] += a[k][i];
            }
        }
    }
    vector<vector<int>> dp(n, vector<int>(20, INT_MIN));
    for (int i = 0; i < 8; i++)
        dp[0][mask[i]] = nmc[0][mask[i]];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if ((mask[j] | mask[k]) == (mask[j] ^ mask[k]))
                    dp[i][mask[j]] = max(dp[i][mask[j]], dp[i - 1][mask[k]] + nmc[i][mask[j]]);
            }
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < 8; i++)
        res = max(res, dp[n - 1][mask[i]]);
    cout << (res <= 0 ? mx : res) << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
