#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
const ll MAX = 1e3 + 5;
ll n, k, l[MAX], r[MAX], fact[MAX], y[MAX];
ll Pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}
void Set()
{
    l[0] = fact[0] = r[k + 3] = 1;
    y[0] = 0;
    for (ll i = 1; i <= k + 2; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        y[i] = (y[i - 1] + Pow(i, k)) % MOD;
        ll tmp = (n - i) % MOD;
        l[i] = (l[i - 1] * tmp) % MOD;
    }
    for (ll i = k + 2; i > 0; i--)
    {
        ll tmp = (n - i) % MOD;
        r[i] = (r[i + 1] * tmp) % MOD;
    }
}
// y[i] = 1^k + 2^k + 3^k + ... + i^k
// l[i] = (n - 1) * (n - 2) * (n - 3) * ... * (n - i)
// r[i] = (n - i) * (n - i - 1) * ... * (n - 1)
void Solve()
{
    cin >> n >> k;
    Set();
    ll ans = 0;
    for (ll i = 1; i <= k + 2; i++)
    {
        ll up = (l[i - 1] * r[i + 1]) % MOD;
        up = (up * y[i]) % MOD;
        ll down = (fact[i - 1] * fact[k + 2 - i] * ((k + 2 - i) & 1LL ? -1LL : 1LL)) % MOD;
        ans += ((up * Pow(down, MOD - 2)) % MOD);
        ans %= MOD;
    }
    cout << (ans + MOD) % MOD << "\n";
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
