#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<vector<int>> dp(n, vector<int>(k, INT_MIN));
    dp[0][a[0] % k] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] %= k;
        for (int j = 0; j < k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - a[i]) % k] + 1);
    }
    cout << dp[n - 1][0] << "\n";
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
