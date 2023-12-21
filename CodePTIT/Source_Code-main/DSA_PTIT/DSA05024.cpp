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
    for (auto &x : a)
        cin >> x;
    vector<ll> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= a[j])
                dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }
    cout << dp[k] << "\n";
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
