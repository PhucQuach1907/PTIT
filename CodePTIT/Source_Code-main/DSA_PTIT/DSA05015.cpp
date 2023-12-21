#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll dp[1005][1005];
ll fact[1005];
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
ll nPk(ll n, ll k)
{
    if (k > n)
        return 0;
    return (nCk(n, k) * fact[k]) % MOD;
}
void Solve()
{
    ll n, k;
    cin >> n >> k;
    cout << nPk(n, k) << "\n";
}
int main()
{
    memset(dp, -1, sizeof(dp));
    fact[0] = fact[1] = 1;
    for (ll i = 2; i <= 1000; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
