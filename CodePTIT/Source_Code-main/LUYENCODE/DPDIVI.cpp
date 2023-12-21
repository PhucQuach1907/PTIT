#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ll>> dp(26, vector<ll>(26, 1));
    for (int i = 2; i <= 25; i++)
    {
        for (int j = 2; j < i; j++)
            dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << "\n";
    }
    return 0;
}
