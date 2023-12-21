#include <iostream>
#define ll long long
#define ull unsigned long long
const ll MOD = 1e9 + 7;
ll pw(ll a, ll b)
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
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll n;
    scanf("%lld", &n);
    ll ans = n * (n + 1);
    ans %= MOD;
    ll tmp = (2 * n + 1) % MOD;
    ans = (ans * tmp) % MOD;
    tmp = pw(6, MOD - 2);
    ans = (ans * tmp) % MOD;
    printf("%lld", ans);
    return 0;
}
