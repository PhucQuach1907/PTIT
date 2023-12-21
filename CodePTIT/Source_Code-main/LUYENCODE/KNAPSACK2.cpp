#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
struct Obj
{
    ll w, v;
};
int main()
{
    ll n, M;
    cin >> n >> M;
    vector<Obj> a(n);
    ll sum = 0;
    for (auto &x : a)
    {
        cin >> x.w >> x.v;
        sum += x.v;
    }
    ll ans = 0;
    vector<vector<ll>> dp(n, vector<ll>(sum + 5, INT_MAX));
    for (ll i = 0; i < n; i++)
        dp[i][0] = 0;
    dp[0][a[0].v] = a[0].w;
    for (ll i = 1; i < n; i++)
    {
        for (ll j = 1; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= a[i].v)
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i].v] + a[i].w);
        }
    }
    for (ll i = sum; i >= 0; i--)
    {
        if (dp[n - 1][i] <= M)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
