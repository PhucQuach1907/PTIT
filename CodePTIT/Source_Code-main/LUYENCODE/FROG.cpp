#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n, k;
    scanf("%lld%lld", &n, &k);
    vector<ll> a(k);
    for (ll i = 0; i < k; i++)
        scanf("%lld", &a[i]);
    ll dp[100];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 0; j < k; j++)
        {
            if (i >= a[j])
                dp[i] += dp[i - a[j]];
        }
    }
    printf("%lld", dp[n]);
    return 0;
}
