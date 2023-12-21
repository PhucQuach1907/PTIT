#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<bool> isBroken(n + 1, 0);
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        isBroken[x] = 1;
    }
    vector<int> dp(n + 1, 0);
    dp[1] = (isBroken[1] ? 0 : 1);
    dp[2] = (isBroken[2] ? 0 : 1 + dp[1]);
    for (int i = 3; i <= n; i++)
        dp[i] = ((!isBroken[i - 1] ? dp[i - 1] : 0) + (!isBroken[i - 2] ? dp[i - 2] : 0)) % MOD;
    cout << dp[n];
    return 0;
}
