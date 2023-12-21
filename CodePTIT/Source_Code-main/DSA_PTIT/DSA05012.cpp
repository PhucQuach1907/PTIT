#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll dp[1005][1005];
ll nCk(ll n, ll k)
{
    if (k == 0 || n == k)
        return 1;
    if (k == 1)
        return n;
    if (dp[n][k] != -1)
        return dp[n][k];
    return (dp[n][k] = (nCk(n - 1, k) % MOD + nCk(n - 1, k - 1) % MOD) % MOD);
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    cout << nCk(n, k) << "\n";
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
