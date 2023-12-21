#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int neg = 0, pos = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] -= k;
        neg += (a[i] < 0 ? a[i] : 0);
        pos += (a[i] > 0 ? a[i] : 0);
    }
    neg = -neg;
    vector<vector<int>> dp(n, vector<int>(pos + neg + 10, -1));
    function<int(int, int)> Cal = [&](int idx, int cur_sum)
    {
        if (idx == n)
            return (cur_sum == 0 ? 1 : 0);
        if (dp[idx][cur_sum + neg] != -1)
            return dp[idx][cur_sum + neg];
        return (dp[idx][cur_sum + neg] = (Cal(idx + 1, cur_sum + a[idx]) + Cal(idx + 1, cur_sum)) % MOD);
    };
    cout << Cal(0, 0) - 1 << "\n";
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
