#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    vector<int> dp(n + 1);
    dp[1] = x;
    for (int i = 2; i <= n; i++)
        dp[i] = (i & 1 ? min(dp[i - 1] + x, dp[(i + 1) / 2] + z + y) : min(dp[i - 1] + x, dp[i / 2] + z));
    cout << dp[n] << "\n";
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
